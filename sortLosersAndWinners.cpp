#include "Student.h"
#include "createDir.h"
#include "readValues.h"
#include "sortLosersAndWinners.h"
#include "strategyOne.h"
#include "strategyTwo.h"

//deque
void sortLosersAndWinners(string fileRead, string fileSortLosers, string fileSortWinners, deque<Student>& studentD, int strategy) {
    stringstream buffer;
    stringstream buffer2;
    deque<Student> losers;
    deque<Student> winners;
    string eil;
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

    readValues(studentD, fileRead, buffer);

    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto& a : studentD) {
        a.setExamFinal((float)0.6 * a.getExamGrade());

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
        vid = (float)sum / gradeNr;

        a.setFinal((float)0.4 * vid + a.getExamFinal());

        sum = 0;

        if (a.getNumOfGrades() % 2 == 0) {
            a.setMedian((unsigned __int64(a.getGrade(a.getNumOfGrades() / 2)) + a.getGrade((a.getNumOfGrades() / 2) - 1)) / (float)2.0);
        }
        else {
            a.setMedian((float)a.getGrade(a.getNumOfGrades() / 2));
        }
        a.setMedFinal(((float)0.4 * a.getMedian()) + ((float)0.6 * a.getExamGrade()));
    }

    //strategy 1

    if (strategy == 1) {
        strategyOne(studentD, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwo(studentD, losers, fileSortLosers, fileSortWinners);
    }
    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
}

//list
void sortLosersAndWinners(string fileRead, string fileSortLosers, string fileSortWinners, list<Student>& studentL, int strategy) {
    stringstream buffer;
    stringstream buffer2;
    list<Student> losers;
    list<Student> winners;
    string eil;
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

    readValues(studentL, fileRead, buffer);

    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    list<Student>::iterator it = studentL.begin();

    for (auto& student : studentL) {
        std::advance(it, 1);
        student.setExamFinal((float)0.6 * student.getExamGrade());

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
        vid = (float)sum / gradeNr;

        student.setFinal((float)0.4 * vid + student.getExamFinal());
        sum = 0;

        if (student.getNumOfGrades() % 2 == 0) {
            student.setMedian((unsigned __int64(student.getGrade(student.getNumOfGrades() / 2)) + student.getGrade((student.getNumOfGrades() / 2) - 1)) / (float)2.00);
        }
        else {
            student.setMedian((float)student.getGrade(student.getNumOfGrades() / 2));
        }
        student.setMedFinal(((float)0.4 * student.getMedian()) + ((float)0.6 * student.getExamGrade()));
    }

    //strategy 1

    if (strategy == 1) {
        strategyOne(studentL, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwo(studentL, losers, fileSortLosers, fileSortWinners);
    }

    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
}

//vector
void sortLosersAndWinners(string fileRead, string fileSortLosers, string fileSortWinners, vector<Student>& student, int strategy) {
    stringstream buffer;
    stringstream buffer2;
    vector<Student> losers;
    vector<Student> winners;
    string eil;
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

    readValues(student, fileRead, buffer);

    start = std::chrono::high_resolution_clock::now();

    student.clear();

    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto& a : student) {
        a.setExamFinal((float)0.6 * a.getExamGrade());

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
        vid = (float)sum / gradeNr;

        a.setFinal((float)0.4 * vid + a.getExamFinal());

        sum = 0;

        if (a.getNumOfGrades() % 2 == 0) {
            a.setMedian((unsigned __int64(a.getGrade(a.getNumOfGrades() / 2)) + a.getGrade((a.getNumOfGrades() / 2) - 1)) / (float)2.00);
        }
        else {
            a.setMedian((float)a.getGrade(a.getNumOfGrades() / 2));
        }
        a.setMedFinal(((float)0.4 * a.getMedian()) + ((float)0.6 * a.getExamGrade()));
    }

    //strategy 1

    if (strategy == 1) {
        strategyOne(student, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwo(student, losers, fileSortLosers, fileSortWinners);
    }

    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
}