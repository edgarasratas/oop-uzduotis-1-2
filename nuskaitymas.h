#pragma once
#include "Student.h"
#include "myVector.h"

void nuskaitymas(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, vector<Student>& student);
void nuskaitymas(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, deque<Student>& studentD);
void nuskaitymas(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, list<Student>& studentL);
void nuskaitymas(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, Vector<Student>& student);