#include "Funkcijos.h"

void sortLosersAndWinnersVector(string fileRead, string fileSortLosers, string fileSortWinners, vector<Student>& student, int strategy) {
	stringstream buffer;
    stringstream buffer2;
    vector<Student> losers;
    vector<Student> winners;
    Student temp;
    string eil;
    int temp2;
    int sum{ 0 };
    float vid;
    int index = 0;
    
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;

    createDir("Losers and winners");

	ifstream fin(fileRead, std::ios::binary);

    try {
        if (fin.fail()) {
            throw std::exception("Tokio failo nera...");
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }

    getline(fin, eil);
    buffer << fin.rdbuf();

    diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << "s\n";

    readValuesVector(student, fileRead, buffer);

    start = std::chrono::high_resolution_clock::now();

    student.clear();

    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto &a : student) {
        a.examFinal = 0.6 * a.examGrade;

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

        if (a.numOfGrades % 2 == 0) {
            a.median = (a.grade[a.numOfGrades / 2] + a.grade[(a.numOfGrades / 2) - 1]) / 2.00;
        }
        else {
            a.median = a.grade[a.numOfGrades / 2];
        }
        a.medFinal = (0.4 * a.median) + (0.6 * a.examGrade);
    }

    //strategy 1

    if (strategy == 1) {
        strategyOneV(student, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwoV(student, losers, fileSortLosers, fileSortWinners);
    }

    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
}