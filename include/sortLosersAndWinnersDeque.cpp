#include "Funkcijos.h"

void sortLosersAndWinnersDeque(string fileRead, string fileSortLosers, string fileSortWinners, deque<Student>& studentD, int strategy) {
    stringstream buffer;
    stringstream buffer2;
    deque<Student> losers;
    deque<Student> winners;
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

    start = std::chrono::high_resolution_clock::now();

    studentD.clear();

    readValuesDeque(studentD, fileRead, buffer);

    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto &a : studentD) {
        a.setExamFinal(0.6 * a.getExamGrade());

        for (int j = 0; j < a.getNumOfGrades() - 1; j++) {
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

        if (a.getNumOfGrades() % 2 == 0) {
            a.setMedian((a.getGrade(a.getNumOfGrades() / 2) + a.getGrade((a.getNumOfGrades() / 2) - 1)) / 2.00);
        }
        else {
            a.setMedian(a.getGrade(a.getNumOfGrades() / 2));
        }
        a.setMedFinal((0.4 * a.getMedian()) + (0.6 * a.getExamGrade()));
    }

    //strategy 1

    if (strategy == 1) {
        strategyOneD(studentD, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwoD(studentD, losers, fileSortLosers, fileSortWinners);
    }
    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
}