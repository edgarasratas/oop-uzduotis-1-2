#include "Header.h"
#include "Funkcijos.h"

void nuskaitymasDeque(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, deque<Student>& studentD) {
    string eil;
    stringstream my_buffer;
    deque<string> myDeque;
    deque<Student> losers;
    deque<Student> winners;
    int sum = 0;
    float vid = 0;
    int strategy;
    int index = 0;

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

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << " s\n";
    cout << "Skaiciuojama..." << '\n';

    start = std::chrono::high_resolution_clock::now();

    readValuesDeque(studentD, fileRead, my_buffer);

    diff = std::chrono::high_resolution_clock::now() - start;

    string output = "";

    for (string& a : myDeque) (a.compare(*myDeque.rbegin()) != 0) ? output += a + "\n" : output += a;
    myDeque.clear();

    ofstream fout(fileWrite);
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    sort(studentD.begin(), studentD.end(), compareByLastName);

    fout << "Pavarde\t\t\t" << "Vardas\t\t" << "Galutinis (Vid)\t\t" << "Galutinis (Med.)\n";
    fout << "------------------------------------------------------------------------\n";
    for (auto &a : studentD) {
        a.examFinal = 0.6 * a.examGrade;
        fout << std::setw(15) << std::left << a.surname
             << std::setw(15) << std::left << a.name;

        for (int j = 0; j < a.numOfGrades - 1; j++) {
            sort(a.grade.begin(), a.grade.end() - 1);
            sum += a.grade[j];
            try {
                if (a.grade[j] < 1 || a.grade[j] > 10 || a.examGrade < 1 || a.examGrade > 10) {
                    throw std::exception("Ivestas netinkamas pazymys...");
                }
            }
            catch (std::exception& e) {
                std::cerr << e.what() << '\n';
                std::exit(EXIT_FAILURE);
            }
        }
        int gradeNr = a.numOfGrades - 1;
        vid = (double)sum / gradeNr;

        a.final = 0.4 * vid + a.examFinal;

        sum = 0;

        if (gradeNr % 2 == 0) {
            a.median = (a.grade[gradeNr / 2] + a.grade[(gradeNr / 2) - 1]) / 2.00;
        }
        else {
            a.median = a.grade[gradeNr / 2];
        }
        a.medFinal = (0.4 * a.median) + (0.6 * a.examGrade);
        fout << fixed << std::setprecision(2) << a.final;

        fout.fill(' ');
        fout.width(20);

        fout << fixed << std::setprecision(2) << a.medFinal << '\n';
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