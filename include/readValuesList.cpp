#include "Funkcijos.h"

void readValuesList(list<Student>& studentD, string fileRead, stringstream& my_buffer)
{
    string eil;
    stringstream buffer2;
    Student temp;
    string name;
    string surname;
    int temp2;

    cout << "Failas skaitomas..." << '\n';

    while (my_buffer) {
        if (!my_buffer.eof()) {

            getline(my_buffer, eil);
            buffer2 << eil;

            buffer2 >> name >> surname;
            temp.setName(name);
            temp.setSurname(surname);
            while (!buffer2.eof()) {
                buffer2 >> temp2;
                temp.addGrade(temp2);
            }
            buffer2.clear();
            temp.setExamGrade(temp.getGrade(temp.containerSize() - 1));
            if (!my_buffer.eof())
                temp.deleteLastGrade();
            temp.setNumOfGrades(temp.containerSize());
            studentD.push_back(temp);
            temp = {};
        }
        else {
            break;
        }
    }
    my_buffer.clear();
}