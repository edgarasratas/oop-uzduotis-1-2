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
        student.setExamFinal(0.6 * student.getExamGrade());

        for (int j = 0; j < student.getNumOfGrades() - 1; j++) {
            sum += student.getGrade(j);
            try {
                if (student.getGrade(j) < 1 || student.getGrade(j) > 10 || student.getExamGrade() < 1 || student.getExamGrade() > 10) {
                    throw std::exception("Ivestas netinkamas pazymys...");
                }
            }
            catch (std::exception& e) {
                std::cerr << e.what() << '\n';
                std::exit(EXIT_FAILURE);
            }
        }
        int gradeNr = student.getNumOfGrades() - 1;
        vid = (double)sum / gradeNr;

        student.setFinal(0.4 * vid + student.getExamFinal());
        sum = 0;

        if (student.getNumOfGrades() % 2 == 0) {
            student.setMedian((student.getGrade(student.getNumOfGrades() / 2) + student.getGrade((student.getNumOfGrades() / 2) - 1)) / 2.00);
        }
        else {
            student.setMedian(student.getGrade(student.getNumOfGrades() / 2));
        }
        student.setMedFinal((0.4 * student.getMedian()) + (0.6 * student.getExamGrade()));
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