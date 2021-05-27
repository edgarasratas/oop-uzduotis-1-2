#pragma once
#include "Student.h"
#include "myVector.h"

void strategyTwo(vector<Student>& studentV, vector<Student>& losers, string fileSortLosers, string fileSortWinners);
void strategyTwo(deque<Student>& studentD, deque<Student>& losers, string fileSortLosers, string fileSortWinners);
void strategyTwo(list<Student>& studentL, list<Student>& losers, string fileSortLosers, string fileSortWinners);
void strategyTwo(Vector<Student>& studentV, Vector<Student>& losers, string fileSortLosers, string fileSortWinners);