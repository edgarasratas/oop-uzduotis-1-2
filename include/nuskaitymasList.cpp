#include "Header.h"
#include "Funkcijos.h"

void nuskaitymasList(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, list<Student>& studentL) {
    string eil;
    stringstream my_buffer;
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
    my_buffer << fin.rdbuf();

    readValuesList(studentL, fileRead, my_buffer);

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
    for (auto &student : studentL) {
        student.setExamFinal(0.6 * student.getExamGrade());
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
        vid = (double)sum / gradeNr;

        student.setFinal(0.4 * vid + student.getExamFinal());

        sum = 0;

        if (gradeNr % 2 == 0) {
            student.setMedian((student.getGrade(gradeNr / 2) + student.getGrade((gradeNr / 2) - 1)) / 2.00);
        }
        else {
            student.setMedian(student.getGrade(gradeNr / 2));
        }
        student.setMedFinal((0.4 * student.getMedian()) + (0.6 * student.getExamGrade()));

        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << student.getFinal();

        fout << std::setw(20) << std::left << fixed << std::setprecision(2) << student.getMedFinal() << '\n';
    }

    diff = std::chrono::high_resolution_clock::now() - start;

    cout << "Sugeneruotas rezultatu failas 'Text files' folderyje\n";
    cout << "Rezultatu failo generavimo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    for (Student &student : studentL) {
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