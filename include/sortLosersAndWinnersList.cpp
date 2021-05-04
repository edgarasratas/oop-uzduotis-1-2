#include "Funkcijos.h"

void sortLosersAndWinnersList(string fileRead, string fileSortLosers, string fileSortWinners, list<Student>& studentL, int strategy) {
    stringstream buffer;
    stringstream buffer2;
    list<Student> losers;
    list<Student> winners;
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

    getline(fin, eil);
    buffer << fin.rdbuf();

    try {
        if (fin.fail()) {
            throw std::exception("Tokio failo nera...");
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }

    diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    readValuesList(studentL, fileRead, buffer);

    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    list<Student>::iterator it = studentL.begin();

    for (auto &student : studentL) {
        std::advance(it, 1);
        student.examFinal = 0.6 * student.examGrade;

        for (int j = 0; j < student.numOfGrades - 1; j++) {
            sum += student.grade[j];
            try {
                if (student.grade[j] < 1 || student.grade[j] > 10 || student.examGrade < 1 || student.examGrade > 10) {
                    throw std::exception("Ivestas netinkamas pazymys...");
                }
            }
            catch (std::exception& e) {
                std::cerr << e.what() << '\n';
                std::exit(EXIT_FAILURE);
            }
        }
        int gradeNr = student.numOfGrades - 1;
        vid = (double)sum / gradeNr;

        student.final = 0.4 * vid + student.examFinal;
        sum = 0;

        if (student.numOfGrades % 2 == 0) {
            student.median = (student.grade[student.numOfGrades / 2] + student.grade[(student.numOfGrades / 2) - 1]) / 2.00;
        }
        else {
            student.median = student.grade[student.numOfGrades / 2];
        }
        student.medFinal = (0.4 * student.median) + (0.6 * student.examGrade);
    }

    //strategy 1

    if (strategy == 1) {
        strategyOneL(studentL, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwoL(studentL, losers, fileSortLosers, fileSortWinners);
    }

    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
}