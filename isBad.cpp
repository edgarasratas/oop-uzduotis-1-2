#include "Student.h"
#include "isBad.h"

bool isBad(const Student& a) {
	return a.getFinal() < 5;
}