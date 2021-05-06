#pragma once
#include "Student.h"

void strategyOne(vector<Student>& studentV, vector<Student>& losers, vector<Student>& winners, string fileSortLosers, string fileSortWinners);
void strategyOne(deque<Student>& studentD, deque<Student>& losers, deque<Student>& winners, string fileSortLosers, string fileSortWinners);
void strategyOne(list<Student>& studentL, list<Student>& losers, list<Student>& winners, string fileSortLosers, string fileSortWinners);