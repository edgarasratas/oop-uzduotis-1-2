#include "Student.h"
#include "nuskaitymas.h"
#include "compareByLastName.h"
#include "createDir.h"
#include "readValues.h"
#include "strategyOne.h"
#include "strategyTwo.h"
#include "myVector.h"

//functions to read the file

//deque
void nuskaitymas(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, deque<Student>& studentD) {
    string eil;
    stringstream my_buffer;
    deque<Student> losers;
    deque<Student> winners;
    int sum = 0;
    float vid = 0;
    int strategy;
    int index = 0;

    createDir("Losers and winners");

    ifstream fin(fileRead, std::ios::binary);

    try {
        if (fin.fail()) {
            throw std::exception("Tokio failo nera...");
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        system("pause");
        std::exit(EXIT_FAILURE);
    }

    do {
        index++;
        if (index != 1)
            cout << "Neteisinga ivestis. Bandykite dar karta.\n";

        cout << "Kokia strategija noretumet panaudoti? (1/2)\n";
        cin >> strategy;

    } while (strategy != 1 && strategy != 2);

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    cout << "Failas skaitomas...\n";

    getline(fin, eil);
    my_buffer << fin.rdbuf();

    readValues(studentD, fileRead, my_buffer); // reads values from the file and puts them in the 'Student' class

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
    for (auto& a : studentD) {
        a.setExamFinal((float)0.6 * a.getExamGrade());
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
        vid = (float)sum / gradeNr;

        a.setFinal((float)0.4 * vid + a.getExamFinal());

        sum = 0;

        if (gradeNr % 2 == 0) {
            a.setMedian((unsigned __int64(a.getGrade(gradeNr / 2)) + a.getGrade((gradeNr / 2) - 1)) / (float)2.00);
        }
        else {
            a.setMedian((float)a.getGrade(gradeNr / 2));
        }
        a.setMedFinal(((float)0.4 * a.getMedian()) + ((float)0.6 * a.getExamGrade()));
        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << a.getFinal();

        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << a.getMedFinal() << '\n';
    }

    diff = std::chrono::high_resolution_clock::now() - start;

    cout << "Sugeneruotas rezultatu failas 'Text files' folderyje\n";
    cout << "Rezultatu failo generavimo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    //strategy 1

    if (strategy == 1) {
        strategyOne(studentD, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwo(studentD, losers, fileSortLosers, fileSortWinners);
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

//list
void nuskaitymas(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, list<Student>& studentL) {
    string eil;
    stringstream my_buffer;
    int sum = 0;
    float vid = 0;
    int strategy;
    int index = 0;

    createDir("Losers and winners");

    ifstream fin(fileRead, std::ios::binary);

    try {
        if (fin.fail()) {
            throw std::exception("Tokio failo nera...");
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        system("pause");
        std::exit(EXIT_FAILURE);
    }

    do {
        index++;
        if (index != 1)
            cout << "Neteisinga ivestis. Bandykite dar karta.\n";

        cout << "Kokia strategija noretumet panaudoti? (1/2)\n";
        cin >> strategy;

    } while (strategy != 1 && strategy != 2);

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    cout << "Failas skaitomas...\n";

    getline(fin, eil);
    my_buffer << fin.rdbuf();

    readValues(studentL, fileRead, my_buffer);

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << " s\n";
    cout << "Skaiciuojama..." << '\n';

    start = std::chrono::high_resolution_clock::now();

    diff = std::chrono::high_resolution_clock::now() - start;

    ofstream fout(fileWrite);
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    studentL.sort(compareByLastName);

    fout << "Pavarde\t\t\t" << "Vardas\t\t" << "Galutinis (Vid)\t\t" << "Galutinis (Med.)\n";
    fout << "------------------------------------------------------------------------\n";
    for (auto& student : studentL) {
        student.setExamFinal((float)0.6 * student.getExamGrade());
        fout << std::setw(15) << std::left << student.getSurname()
            << std::setw(15) << std::left << student.getName();

        for (int j = 0; j < student.getNumOfGrades() - 1; j++) {
            student.deleteLastGrade();
            student.sortGrades();
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

        if (gradeNr % 2 == 0) {
            student.setMedian((unsigned __int64(student.getGrade(gradeNr / 2)) + student.getGrade((gradeNr / 2) - 1)) / (float)2.00);
        }
        else {
            student.setMedian((float)student.getGrade(gradeNr / 2));
        }
        student.setMedFinal(((float)0.4 * student.getMedian()) + ((float)0.6 * student.getExamGrade()));

        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << student.getFinal();

        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << student.getMedFinal() << '\n';
    }

    diff = std::chrono::high_resolution_clock::now() - start;

    cout << "Sugeneruotas rezultatu failas 'Text files' folderyje\n";
    cout << "Rezultatu failo generavimo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    for (Student& student : studentL) {
        if (student.getFinal() < 5) {
            foutLosers << std::setw(15) << std::left << student.getName()
                << std::setw(15) << std::left << student.getSurname()
                << std::setw(15) << std::left << fixed << std::setprecision(2) << student.getFinal() << '\n';
        }
        else if (student.getFinal() >= 5) {
            foutWinners << std::setw(15) << std::left << student.getName()
                << std::setw(15) << std::left << student.getSurname()
                << std::setw(15) << std::left << fixed << std::setprecision(2) << student.getFinal() << '\n';
        }
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

//vector
void nuskaitymas(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, vector<Student>& student) {
    string eil;
    vector<Student> losers;
    vector<Student> winners;
    stringstream my_buffer;
    stringstream buffer2;
    int sum = 0;
    float vid = 0;
    int strategy;
    int index = 0;

    createDir("Losers and winners");

    ifstream fin(fileRead, std::ios::binary);

    try {
        if (fin.fail()) {
            throw std::exception("Tokio failo nera...");
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        system("pause");
        std::exit(EXIT_FAILURE);
    }

    do {
        index++;
        if (index != 1)
            cout << "Neteisinga ivestis. Bandykite dar karta.\n";

        cout << "Kokia strategija noretumet panaudoti? (1/2)\n";
        cin >> strategy;

    } while (strategy != 1 && strategy != 2);

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    cout << "Failas skaitomas...\n";

    getline(fin, eil);
    my_buffer << fin.rdbuf();

    readValues(student, fileRead, my_buffer);

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << " s\n";
    cout << "Skaiciuojama..." << '\n';

    start = std::chrono::high_resolution_clock::now();

    diff = std::chrono::high_resolution_clock::now() - start;

    ofstream fout(fileWrite);
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    sort(student.begin(), student.end(), compareByLastName);

    fout << "Pavarde\t\t\t" << "Vardas\t\t" << "Galutinis (Vid)\t\t" << "Galutinis (Med.)\n";
    fout << "------------------------------------------------------------------------\n";

    for (auto& a : student) {
        a.setExamFinal((float)0.6 * a.getExamGrade());
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
        vid = (float)sum / gradeNr;

        a.setFinal((float)0.4 * vid + a.getExamFinal());

        sum = 0;
        if (gradeNr % 2 == 0) {
            a.setMedian((a.getGrade((gradeNr - 1) / 2)
                + unsigned __int64(a.getGrade(gradeNr / 2))) / (float)2.0);
        }
        else {
            a.setMedian((float)a.getGrade(gradeNr / 2));
        }
        a.setMedFinal((float)(0.4 * a.getMedian()) + (float)(0.6 * a.getExamGrade()));
        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << a.getFinal();

        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << a.getMedFinal() << '\n';
    }

    diff = std::chrono::high_resolution_clock::now() - start;

    cout << "Sugeneruotas rezultatu failas 'Text files' folderyje\n";
    cout << "Rezultatu failo generavimo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    //strategy 1

    if (strategy == 1) {
        strategyOne(student, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwo(student, losers, fileSortLosers, fileSortWinners);
    }
    fin.close();
    fout.close();

    diff = std::chrono::high_resolution_clock::now() - start;
    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - st;
    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
    cout << "Visas sugaistas laikas: " << diff2.count() << " s\n\n";
}

//myVector
void nuskaitymas(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, Vector<Student>& student) {
    string eil;
    Vector<Student> losers;
    Vector<Student> winners;
    stringstream my_buffer;
    stringstream buffer2;
    int sum = 0;
    float vid = 0;
    int strategy;
    int index = 0;

    createDir("Losers and winners");

    ifstream fin(fileRead, std::ios::binary);

    try {
        if (fin.fail()) {
            throw std::exception("Tokio failo nera...");
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        system("pause");
        std::exit(EXIT_FAILURE);
    }

    do {
        index++;
        if (index != 1)
            cout << "Neteisinga ivestis. Bandykite dar karta.\n";

        cout << "Kokia strategija noretumet panaudoti? (1/2)\n";
        cin >> strategy;

    } while (strategy != 1 && strategy != 2);

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    cout << "Failas skaitomas...\n";

    getline(fin, eil);
    my_buffer << fin.rdbuf();

    readValues(student, fileRead, my_buffer);

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << " s\n";
    cout << "Skaiciuojama..." << '\n';

    start = std::chrono::high_resolution_clock::now();

    diff = std::chrono::high_resolution_clock::now() - start;

    ofstream fout(fileWrite);
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    fout << "Pavarde\t\t\t" << "Vardas\t\t" << "Galutinis (Vid)\t\t" << "Galutinis (Med.)\n";
    fout << "------------------------------------------------------------------------\n";

    for (auto a : student) {
        a.setExamFinal((float)0.6 * a.getExamGrade());
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
        vid = (float)sum / gradeNr;

        a.setFinal((float)0.4 * vid + a.getExamFinal());

        sum = 0;
        if (gradeNr % 2 == 0) {
            a.setMedian((a.getGrade((gradeNr - 1) / 2)
                + unsigned __int64(a.getGrade(gradeNr / 2))) / (float)2.0);
        }
        else {
            a.setMedian((float)a.getGrade(gradeNr / 2));
        }
        a.setMedFinal((float)(0.4 * a.getMedian()) + (float)(0.6 * a.getExamGrade()));
        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << a.getFinal();

        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << a.getMedFinal() << '\n';
    }

    diff = std::chrono::high_resolution_clock::now() - start;

    cout << "Sugeneruotas rezultatu failas 'Text files' folderyje\n";
    cout << "Rezultatu failo generavimo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    //strategy 1

    if (strategy == 1) {
        strategyOne(student, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwo(student, losers, fileSortLosers, fileSortWinners);
    }
    fin.close();
    fout.close();

    diff = std::chrono::high_resolution_clock::now() - start;
    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - st;
    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
    cout << "Visas sugaistas laikas: " << diff2.count() << " s\n\n";
}