#include "Student.h"
#include "readValues.h"

//deque
void readValues(deque<Student>& studentD, string fileRead, stringstream& my_buffer)
{
    string eil;
    stringstream buffer2;
    string name;
    string surname;
    Student temp;
    deque<Student> studentTemp;
    int temp2;

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
            temp.setExamGrade(temp.getGrade((int)temp.containerSize() - 1));
            if (!my_buffer.eof())
                temp.deleteLastGrade();
            temp.setNumOfGrades((int)temp.containerSize());
            studentD.push_back(temp);
            temp = {};
        }
        else {
            break;
        }
    }
    my_buffer.clear();
}

//list
void readValues(list<Student>& studentL, string fileRead, stringstream& my_buffer)
{
    string eil;
    stringstream buffer2;
    string name;
    string surname;
    Student temp;
    int temp2;

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
            temp.setExamGrade(temp.getGrade((int)temp.containerSize() - 1));
            if (!my_buffer.eof())
                temp.deleteLastGrade();
            temp.setNumOfGrades((int)temp.containerSize());
            studentL.push_back(temp);
            temp = {};
        }
        else {
            break;
        }
    }
    my_buffer.clear();
}

//vector
void readValues(vector<Student>& studentV, string fileRead, stringstream& my_buffer)
{
    string eil;
    stringstream buffer2;
    Student temp;
    int tempGrade;
    string name;
    string surname;
    int k = 0;
    
    while (my_buffer)
    {
        if (!my_buffer.eof())
        {
            getline(my_buffer, eil);
            buffer2 << eil;
            buffer2 >> name >> surname;
            while (!buffer2.eof())
            {
                buffer2 >> tempGrade;
                temp.addGrade(tempGrade);
            }
            buffer2.clear();
            temp.setExamGrade(temp.getGrade((int)temp.containerSize() - 1));
            if (!my_buffer.eof())
            {
                temp.deleteLastGrade();
            }

            temp.setNumOfGrades((int)temp.containerSize());
            studentV.push_back(temp);
            studentV[k].setName(name);
            studentV[k].setSurname(surname);
            k++;
            temp = {};
        }
        else {
            break;
        }
    }
    my_buffer.clear();
}