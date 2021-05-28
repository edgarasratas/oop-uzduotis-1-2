#include "Student.h"
#include "strategyOne.h"
#include "myVector.h"

//deque
void strategyOne(deque<Student>& studentD, deque<Student>& losers, deque<Student>& winners, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (int i = 0; i < studentD.size(); i++)
    {
        if (studentD[i].getFinal() < 5)
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

    for (Student& a : losers)
    {
        foutLosers << std::setw(15) << std::left << a.getName()
            << std::setw(15) << std::left << a.getSurname()
            << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }

    for (Student& a : winners)
    {
        foutWinners << std::setw(15) << std::left << a.getName()
            << std::setw(15) << std::left << a.getSurname()
            << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }
}

//list
void strategyOne(list<Student>& studentL, list<Student>& losers, list<Student>& winners, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto& student : studentL) {
        if (student.getFinal() < 5) {
            losers.push_back(student);
        }
        else if (student.getFinal() >= 5) {
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

    for (Student& a : losers) {
        foutLosers << std::setw(15) << std::left << a.getName()
            << std::setw(15) << std::left << a.getSurname()
            << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }

    for (Student& a : winners) {
        foutWinners << std::setw(15) << std::left << a.getName()
            << std::setw(15) << std::left << a.getSurname()
            << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }
}

//vector
void strategyOne(vector<Student>& studentV, vector<Student>& losers, vector<Student>& winners, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto& a : studentV) {
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

    for (Student& a : losers) {
        foutLosers << std::setw(15) << std::left << a.getName()
            << std::setw(15) << std::left << a.getSurname()
            << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }

    for (Student& a : winners) {
        foutWinners << std::setw(15) << std::left << a.getName()
            << std::setw(15) << std::left << a.getSurname()
            << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }
}

//myVector
void strategyOne(Vector<Student>& studentV, Vector<Student>& losers, Vector<Student>& winners, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto a : studentV) {
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

    for (Student a : losers) {
        foutLosers << std::setw(15) << std::left << a.getName()
            << std::setw(15) << std::left << a.getSurname()
            << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }

    for (Student a : winners) {
        foutWinners << std::setw(15) << std::left << a.getName()
            << std::setw(15) << std::left << a.getSurname()
            << std::setw(15) << std::left << fixed << std::setprecision(2) << a.getFinal() << '\n';
    }
}