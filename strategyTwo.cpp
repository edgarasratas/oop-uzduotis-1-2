#include "Student.h"
#include "isBad.h"
#include "strategyTwo.h"
#include "myVector.h"

//deque
void strategyTwo(deque<Student>& studentD, deque<Student>& losers, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (int i = 0; i < studentD.size(); i++)
    {
        if (studentD[i].getFinal() < 5)
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

    for (Student& a : losers)
    {
        foutLosers << std::setw(15) << std::left << a.getName()
                   << std::setw(15) << std::left << a.getSurname()
                   << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }

    for (Student& a : studentD)
    {
        foutWinners << std::setw(15) << std::left << a.getName()
                    << std::setw(15) << std::left << a.getSurname()
                    << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }
}

//list
void strategyTwo(list<Student>& studentL, list<Student>& losers, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto& student : studentL) {
        if (student.getFinal() < 5) {
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

    for (Student& a : losers) {
        foutLosers << std::setw(15) << std::left << a.getName()
                   << std::setw(15) << std::left << a.getSurname()
                   << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }

    for (Student& a : studentL) {
        foutWinners << std::setw(15) << std::left << a.getName()
                    << std::setw(15) << std::left << a.getSurname()
                    << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }
}

//vector
void strategyTwo(vector<Student>& studentV, vector<Student>& losers, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto& a : studentV) {
        if (a.getFinal() < 5) {
            losers.push_back(a);
        }
    }

    studentV.erase(std::remove_if(studentV.begin(), studentV.end(), isBad), studentV.end());

    foutLosers << std::setw(15) << std::left << "Vardas"
               << std::setw(15) << std::left << "Pavarde"
               << std::setw(15) << std::left << "Galutinis (vid.)" << '\n'
               << "--------------------------------------------- " << '\n';

    foutWinners << std::setw(15) << std::left << "Vardas"
                << std::setw(15) << std::left << "Pavarde"
                << std::setw(15) << std::left << "Galutinis (vid.)" << '\n'
                << "--------------------------------------------- " << '\n';

    for (Student& a : losers) {
        foutLosers << std::setw(15) << std::left << a.getName()
                   << std::setw(15) << std::left << a.getSurname()
                   << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }

    for (Student& a : studentV) {
        foutWinners << std::setw(15) << std::left << a.getName()
                    << std::setw(15) << std::left << a.getSurname()
                    << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }
}

//myVector
void strategyTwo(Vector<Student>& studentV, Vector<Student>& losers, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto a : studentV) {
        if (a.getFinal() < 5) {
            losers.push_back(a);
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

    for (Student a : losers) {
        foutLosers << std::setw(15) << std::left << a.getName()
            << std::setw(15) << std::left << a.getSurname()
            << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }

    for (Student a : studentV) {
        foutWinners << std::setw(15) << std::left << a.getName()
            << std::setw(15) << std::left << a.getSurname()
            << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }
}