#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <chrono>
#include <sstream>
#include <time.h>
#include <Windows.h>
#include <direct.h>

#define GetCurrentDir _getcwd

using std::cout;
using std::cin;
using std::string;
using std::sort;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::chrono::high_resolution_clock;
using std::getline;
using std::stringstream;
using std::fixed;
using std::setprecision;
using std::fill;
using std::deque;
using std::list;
using std::find_if;

//Student class

class Student {
private:
	string name;
	string surname;
	float examFinal;
	int examGrade;
	int numOfGrades;
	float final;
	float median = 0;
	float medFinal;
	vector<int> grade;
public:
	//getters

	string getName() const { return name; } 
	string getSurname() const { return surname; } 
	float getExamFinal() const { return examFinal; } 
	int getExamGrade() const { return examGrade; }
	int getNumOfGrades() const { return numOfGrades; }
	float getFinal() const { return final; }
	float getMedian() const { return median; }
	float getMedFinal() const { return medFinal; }
	int getGrade(int i) const { return grade[i]; }
	int containerSize() const { return grade.size(); }

	//setters

	void setName(string x) { name = x; }
	void setSurname(string x) { surname = x; }
	void setExamFinal(float x) { examFinal = x; }
	void setExamGrade(int x) { examGrade = x; }
	void setNumOfGrades(int x) { numOfGrades = x; }
	void setFinal(float x) { final = x; }
	void setMedian(float x) { median = x; }
	void setMedFinal(float x) { medFinal = x; }

	//functions for the 'grade' vector

	void addGrade(int x) {
		grade.push_back(x);
		grade.shrink_to_fit();
	}

	void deleteLastGrade() { grade.pop_back(); }

	void sortGrades() { sort(grade.begin(), grade.end()); }
};