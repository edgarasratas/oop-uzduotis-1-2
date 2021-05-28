#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
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

//Human class

class Human {
protected:
	string m_name = "";
	string m_surname = "";
public:
	virtual ~Human() = 0;

	virtual const string& getName() const { return m_name; }
	virtual const string& getSurname() const { return m_surname; }

	virtual void setName(string x) { this->m_name = x; }
	virtual void setSurname(string x) { this->m_surname = x; }
};

//Student class

class Student: public Human {
private:
	float m_examFinal = 0;
	int m_examGrade = 0;
	int m_numOfGrades = 0;
	float m_final = 0;
	float m_median = 0;
	float m_medFinal = 0;
	vector<int> m_grade;
public:

	//getters

	float getExamFinal() const { return m_examFinal; }
	int getExamGrade() const { return m_examGrade; }
	int getNumOfGrades() const { return m_numOfGrades; }
	float getFinal() const { return m_final; }
	float getMedian() const { return m_median; }
	float getMedFinal() const { return m_medFinal; }
	int getGrade(int i) const { return m_grade[i]; }
	size_t containerSize() const { return m_grade.size(); }

	//setters

	void setExamFinal(float x) { this->m_examFinal = x; }
	void setExamGrade(int x) { this->m_examGrade = x; }
	void setNumOfGrades(int x) { this->m_numOfGrades = x; }
	void setFinal(float x) { this->m_final = x; }
	void setMedian(float x) { this->m_median = x; }
	void setMedFinal(float x) { this->m_medFinal = x; }

	//functions for the 'grade' vector

	void addGrade(int x) {
		m_grade.push_back(x);
		//m_grade.shrink_to_fit();
	}

	void deleteLastGrade() { m_grade.pop_back(); }

	void sortGrades() { sort(m_grade.begin(), m_grade.end()); }
	
	// Destructor
	~Student() = default;

	// Copy constructor
	Student() {};
	Student(const Student&);

	// Copy assignment operator
	Student& operator=(const Student&);
};