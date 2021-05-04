#include "Header.h"
#include "Funkcijos.h"

//function to read the file 

void nuskaitymasDeque(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, deque<Student>& studentD) {
    string eil;
    stringstream my_buffer;
    deque<Student> losers;
    deque<Student> winners;
    int sum = 0;
    float vid = 0;
    int strategy;
    int index = 0;

    //confusing af, need index and these if statements to avoid certain bugs
    do {
        index++;
        if (index != 1)
            cout << "Neteisinga ivestis. Bandykite dar karta.\n";

        cout << "Kokia strategija noretumet panaudoti? (1/2)\n";
        cin >> strategy;

        if (strategy == 1 || strategy == 2)
            break;
    } while (strategy != 1 || strategy != 2);

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    createDir("Losers and winners");

    ifstream fin(fileRead, std::ios::binary);

    getline(fin, eil);
    my_buffer << fin.rdbuf();

    try {
        if (fin.fail()) {
            throw std::exception("Tokio failo nera...");
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }

    readValuesDeque(studentD, fileRead, my_buffer); // reads values from the file and puts them in the 'Student' class

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << " s\n";
    cout << "Skaiciuojama..." << '\n';

    start = std::chrono::high_resolution_clock::now();

    diff = std::chrono::high_resolution_clock::now() - start;

    ofstream fout(fileWrite);
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    sort(studentD.begin(), studentD.end(), compareByLastName); //sorts students alphabetically

    fout << "Pavarde\t\t\t" << "Vardas\t\t" << "Galutinis (Vid)\t\t" << "Galutinis (Med.)\n"
         << "------------------------------------------------------------------------\n";

    //calculates the final grade and the final median grade
    for (auto &a : studentD) {
        a.setExamFinal(0.6 * a.getExamGrade());
        fout << std::setw(15) << std::left << a.getSurname()
             << std::setw(15) << std::left << a.getName();

        for (int j = 0; j < a.getNumOfGrades() - 1; j++) {
            a.deleteLastGrade();
            a.sortGrades();
            sum += a.getGrade(j);
            try {
                if (a.getGrade(j) < 1 || a.getGrade(j) > 10 || a.getExamGrade() < 1 || a.getExamGrade() > 10) {
                    throw std::exception("Ivestas netinkamas pazymys...");
                }
            }
            catch (std::exception& e) {
                std::cerr << e.what() << '\n';
                std::exit(EXIT_FAILURE);
            }
        }
        int gradeNr = a.getNumOfGrades() - 1;
        vid = (double)sum / gradeNr;

        a.setFinal(0.4 * vid + a.getExamFinal());

        sum = 0;

        if (gradeNr % 2 == 0) {
            a.setMedian((a.getGrade(gradeNr / 2) + a.getGrade((gradeNr / 2) - 1)) / 2.00);
        }
        else {
            a.setMedian(a.getGrade(gradeNr / 2));
        }
        a.setMedFinal((0.4 * a.getMedian()) + (0.6 * a.getExamGrade()));
        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << a.getFinal();

        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << a.getMedFinal() << '\n';
    }
    
    diff = std::chrono::high_resolution_clock::now() - start;

    cout << "Sugeneruotas rezultatu failas 'Text files' folderyje\n";
    cout << "Rezultatu failo generavimo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    //strategy 1

    if (strategy == 1) {
        strategyOneD(studentD, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwoD(studentD, losers, fileSortLosers, fileSortWinners);
    }

    fin.close();
    fout.close();

    diff = std::chrono::high_resolution_clock::now() - start;
    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - st;
    cout << "Sugeneruotas failas 'Text files' folderyje\n";
    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
    cout << "Visas sugaistas laikas: " << diff2.count() << " s\n\n";
}