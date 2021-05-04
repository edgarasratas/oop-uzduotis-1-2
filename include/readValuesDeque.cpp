#include "Funkcijos.h"

void readValuesDeque(deque<Student>& studentD, string fileRead, stringstream& my_buffer)
{
    string eil;
    stringstream buffer2;
    Student temp;
    int temp2;

    cout << "Failas skaitomas..." << '\n';

    while (my_buffer) {
        if (!my_buffer.eof()) {

            getline(my_buffer, eil);
            buffer2 << eil;

            buffer2 >> temp.name >> temp.surname;
            while (!buffer2.eof()) {
                buffer2 >> temp2;
                temp.grade.push_back(temp2);
            }
            buffer2.clear();
            temp.examGrade = temp.grade[temp.grade.size() - 1];
            if (!my_buffer.eof())
                temp.grade.pop_back();
            temp.grade.shrink_to_fit();
            temp.numOfGrades = temp.grade.size();
            studentD.push_back(temp);
            temp = {};
        }
        else {
            break;
        }
    }
    my_buffer.clear();
}