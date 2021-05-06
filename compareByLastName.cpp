#include "Student.h"
#include "compareByLastName.h"

bool compareByLastName(const Student& a, const Student& b) {
    return a.getName() < b.getName();
}