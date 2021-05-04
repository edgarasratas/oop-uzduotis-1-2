#include "Funkcijos.h"

void strategyOneV(vector<Student>&student, vector<Student>& losers, vector<Student>& winners, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

        for (auto &a : student) {
            if (a.getFinal() < 5) {
                losers.push_back(a);
            }
            else if (a.getFinal() >= 5) {
                winners.push_back(a);
            }
        }

        foutLosers << std::setw(15) << std::left << "Vardas"
                   << std::setw(15) << std::left << "Pavarde"
                   << std::setw(15) << std::left << "Galutinis (vid.)" << '\n'
                   << "--------------------------------------------- " << '\n';

        foutWinners << std::setw(15) << std::left << "Vardas"
                    << std::setw(15) << std::left << "Pavarde"
                    << std::setw(15) << std::left << "Galutinis (vid.)" << '\n'
                    << "--------------------------------------------- " << '\n';

        for (Student &a : losers) {
            foutLosers << std::setw(15) << std::left << a.getName()
                       << std::setw(15) << std::left << a.getSurname()
                       << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
        }

        for (Student &a : winners) {
            foutWinners << std::setw(15) << std::left << a.getName()
                        << std::setw(15) << std::left << a.getSurname()
                        << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
        }
}

void strategyTwoV(vector<Student>& student, vector<Student>& losers, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto &a : student) {
        if (a.getFinal() < 5) {
            losers.push_back(a);
        }
    }

    student.erase(std::remove_if(student.begin(), student.end(), isBad), student.end());

    foutLosers << std::setw(15) << std::left << "Vardas"
               << std::setw(15) << std::left << "Pavarde"
               << std::setw(15) << std::left << "Galutinis (vid.)" << '\n'
               << "--------------------------------------------- " << '\n';

    foutWinners << std::setw(15) << std::left << "Vardas"
                << std::setw(15) << std::left << "Pavarde"
                << std::setw(15) << std::left << "Galutinis (vid.)" << '\n'
                << "--------------------------------------------- " << '\n';

    for (Student &a : losers) {
        foutLosers << std::setw(15) << std::left << a.getName()
                   << std::setw(15) << std::left << a.getSurname()
                   << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }

    for (Student &a : student) {
        foutWinners << std::setw(15) << std::left << a.getName()
                    << std::setw(15) << std::left << a.getSurname()
                    << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }
}