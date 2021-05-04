#include "Funkcijos.h"

void strategyOneD(deque<Student>& studentD, deque<Student>& losers, deque<Student>& winners, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (int i = 0; i < studentD.size(); i++)
    {
        if (studentD[i].final < 5)
        {
            losers.push_back(studentD[i]);
        }
        else
        {
            winners.push_back(studentD[i]);
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

    for (Student &a : losers)
    {
        foutLosers << std::setw(15) << std::left << a.name
                   << std::setw(15) << std::left << a.surname
                   << std::setw(15) << std::left << fixed << std::setprecision(2) << a.final << '\n';
    }

    for (Student &a : winners)
    {
        foutWinners << std::setw(15) << std::left << a.name
                    << std::setw(15) << std::left << a.surname
                    << std::setw(15) << std::left << fixed << std::setprecision(2) << a.final << '\n';
    }
}

void strategyTwoD(deque<Student>& studentD, deque<Student>& losers, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (int i = 0; i < studentD.size(); i++)
    {
        if (studentD[i].final < 5)
        {
            losers.push_back(studentD[i]);
        }
    }

    studentD.erase(std::remove_if(studentD.begin(), studentD.end(), isBad), studentD.end());

    foutLosers << std::setw(15) << std::left << "Vardas"
               << std::setw(15) << std::left << "Pavarde"
               << std::setw(15) << std::left << "Galutinis (vid.)" << '\n'
               << "--------------------------------------------- " << '\n';

    foutWinners << std::setw(15) << std::left << "Vardas"
                << std::setw(15) << std::left << "Pavarde"
                << std::setw(15) << std::left << "Galutinis (vid.)" << '\n'
                << "--------------------------------------------- " << '\n';

    for (Student &a : losers)
    {
        foutLosers << std::setw(15) << std::left << a.name
                   << std::setw(15) << std::left << a.surname
                   << std::setw(15) << std::left << fixed << std::setprecision(2) << a.final << '\n';
    }

    for (Student &a : studentD)
    {
        foutWinners << std::setw(15) << std::left << a.name
                    << std::setw(15) << std::left << a.surname
                    << std::setw(15) << std::left << fixed << std::setprecision(2) << a.final << '\n';
    }
}