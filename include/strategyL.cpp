#include "Funkcijos.h"

void strategyOneL(list<Student>& studentL, list<Student>& losers, list<Student>& winners, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto &student : studentL) {
        if (student.final < 5) {
            losers.push_back(student);
        }
        else if (student.final >= 5) {
            winners.push_back(student);
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
        foutLosers << std::setw(15) << std::left << a.name
                   << std::setw(15) << std::left << a.surname
                   << std::setw(15) << std::left << fixed << std::setprecision(2) << a.final << '\n';
    }

    for (Student &a : winners) {
        foutWinners << std::setw(15) << std::left << a.name
                    << std::setw(15) << std::left << a.surname
                    << std::setw(15) << std::left << fixed << std::setprecision(2) << a.final << '\n';
    }
}

void strategyTwoL(list<Student>& studentL, list<Student>& losers, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto &student : studentL) {
        if (student.final < 5) {
            losers.push_back(student);
        }
    }

    studentL.erase(std::remove_if(studentL.begin(), studentL.end(), isBad), studentL.end());

    foutLosers << std::setw(15) << std::left << "Vardas"
               << std::setw(15) << std::left << "Pavarde"
               << std::setw(15) << std::left << "Galutinis (vid.)" << '\n'
               << "--------------------------------------------- " << '\n';

    foutWinners << std::setw(15) << std::left << "Vardas"
                << std::setw(15) << std::left << "Pavarde"
                << std::setw(15) << std::left << "Galutinis (vid.)" << '\n'
                << "--------------------------------------------- " << '\n';

    for (Student &a : losers) {
        foutLosers << std::setw(15) << std::left << a.name
                   << std::setw(15) << std::left << a.surname
                   << std::setw(15) << std::left << fixed << std::setprecision(2) << a.final << '\n';
    }

    for (Student &a : studentL) {
        foutWinners << std::setw(15) << std::left << a.name
                    << std::setw(15) << std::left << a.surname
                    << std::setw(15) << std::left << fixed << std::setprecision(2) << a.final << '\n';
    }
}