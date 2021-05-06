#pragma once
#include "Student.h"

void sortLosersAndWinners(string fileRead, string fileSortLosers, string fileSortWinners, vector<Student>& student, int strategy);
void sortLosersAndWinners(string fileRead, string fileSortLosers, string fileSortWinners, deque<Student>& studentD, int strategy);
void sortLosersAndWinners(string fileRead, string fileSortLosers, string fileSortWinners, list<Student>& studentL, int strategy);