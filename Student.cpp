#include "Student.h"

Human::~Human() {
}

// Copy constructor

Student::Student(const Student& student)
{
	m_examFinal = student.m_examFinal;
	m_examGrade = student.m_examGrade;
	m_numOfGrades = student.m_numOfGrades;
	m_final = student.m_final;
	m_median = student.m_median;
	m_medFinal = student.m_medFinal;
	m_grade = student.m_grade;
}

//Copy assignment operator

Student& Student::operator =(const Student& student)
{
	if (this == &student)
		return *this;

	m_examFinal = student.m_examFinal;
	m_examGrade = student.m_examGrade;
	m_numOfGrades = student.m_numOfGrades;
	m_final = student.m_final;
	m_median = student.m_median;
	m_medFinal = student.m_medFinal;
	m_grade = student.m_grade;

	return *this;
}