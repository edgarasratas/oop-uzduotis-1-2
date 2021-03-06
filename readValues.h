#pragma once
#include "Student.h"
#include "myVector.h"

void readValues(vector<Student>& studentD, string fileRead, stringstream& my_buffer);
void readValues(deque<Student>& studentD, string fileRead, stringstream& my_buffer);
void readValues(list<Student>& studentL, string fileRead, stringstream& my_buffer);
void readValues(Vector<Student>& studentL, string fileRead, stringstream& my_buffer);