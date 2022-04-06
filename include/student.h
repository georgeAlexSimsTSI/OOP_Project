#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include <string>
using std::string;

class student : public person
{
private:
    unsigned int studentNumber;
    unsigned int yearOfStudy;
    unsigned int enrollmentYear;

public:
    student(unsigned int studentNumber, unsigned int yearOfStudy, unsigned int enrollmentYear, string firstName, string lastName);
    student(unsigned int studentNumber, unsigned int yearOfStudy, unsigned int enrollmentYear, person &person_);
    unsigned int getStudentNumber();
    unsigned int getYearOfStudy();
    unsigned int getenrollmentYear();
};

#endif