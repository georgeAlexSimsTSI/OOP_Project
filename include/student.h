#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include "moduleInstance.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

/**
 * @brief Derived class from person that adds variables for a Student 
 */
class student : public person
{
private:
    unsigned int studentNumber;
    unsigned int yearOfStudy;
    unsigned int enrollmentYear;
    // vector<moduleInstance> modules;
    
public:
    student(unsigned int studentNumber, unsigned int yearOfStudy, unsigned int enrollmentYear, person &person_);
    unsigned int getStudentNumber();
    unsigned int getYearOfStudy();
    unsigned int getenrollmentYear();
    bool passYear(unsigned int year);
    // vector<moduleInstance> &getModules();
    // vector<moduleInstance> &getModules(unsigned int year);
    // void addModule(moduleInstance &moduleInstance_);
    // void removeModule(moduleInstance &moduleInstance_);
};

#endif