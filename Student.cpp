#include "Student.h"

// Copy constructor
Student::Student(const Student& student)
{
	name = student.name;
	surname = student.surname;
	examFinal = student.examFinal;
	examGrade = student.examGrade;
	numOfGrades = student.numOfGrades;
	final = student.final;
	median = student.median;
	medFinal = student.medFinal;
	grade = student.grade;
}

//Copy assignment operator
Student& Student::operator =(const Student& student)
{
	if (this == &student)
		return *this;

	name = student.name;
	surname = student.surname;
	examFinal = student.examFinal;
	examGrade = student.examGrade;
	numOfGrades = student.numOfGrades;
	final = student.final;
	median = student.median;
	medFinal = student.medFinal;
	grade = student.grade;

	return *this;
}