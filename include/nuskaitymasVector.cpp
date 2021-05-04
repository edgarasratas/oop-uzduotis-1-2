#include "Header.h"
#include "Funkcijos.h"

void nuskaitymasVector(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, vector<Student>& student) {
    string eil;
    vector<Student> losers;
    vector<Student> winners;
    stringstream my_buffer;
    stringstream buffer2;
    Student temp;
    int temp2;
    int sum = 0;
    float vid = 0;
    int strategy;
    int index = 0;
    
    cout << "Test: " << typeid(student).name() << '\n';
    
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

    readValuesVector(student, fileRead, my_buffer);

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << " s\n";
    cout << "Skaiciuojama..." << '\n';

    diff = std::chrono::high_resolution_clock::now() - start;

    string output = "";

    ofstream fout(fileWrite);
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);


   sort(student.begin(), student.end(), compareByLastName);



    fout << "Pavarde\t\t\t" << "Vardas\t\t" << "Galutinis (Vid)\t\t" << "Galutinis (Med.)\n";
    fout << "------------------------------------------------------------------------\n";

    for (auto& a : student) {
        a.examFinal = 0.6 * a.examGrade;
        fout << a.surname << a.name << "\t\t";
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
            a.median = (a.grade[(gradeNr - 1) / 2]
                + a.grade[gradeNr / 2]) / 2.0;
        }
        else {
            a.median = a.grade[gradeNr / 2];
        }
        a.medFinal = (0.4 * a.median) + (0.6 * a.examGrade);
        fout << std::setw(15) << std::left << fixed << std::setprecision(2) << a.final;

        fout << std::setw(15) << std::left << fixed << std::setprecision(2) << a.medFinal << '\n';
    }

    diff = std::chrono::high_resolution_clock::now() - start;

    cout << "Sugeneruotas rezultatu failas 'Text files' folderyje\n";
    cout << "Rezultatu failo generavimo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    //strategy 1

    if (strategy == 1) {
        strategyOneV(student, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwoV(student, losers, fileSortLosers, fileSortWinners);
    }
    fin.close();
    fout.close();

    diff = std::chrono::high_resolution_clock::now() - start;
    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - st;
    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
    cout << "Visas sugaistas laikas: " << diff2.count() << " s\n\n";
}