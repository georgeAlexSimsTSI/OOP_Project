#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include "moduleInstance.h"
#include <string>
#include <map>
using std::map;
using std::string;

/**
 * @brief Derived class from Person that adds variables for a Student
 */
class Student : public Person
{
private:
    unsigned int StudentNumber;
    unsigned int YearOfStudy;
    unsigned int enrollmentYear;
    map<string, ModuleInstance *> modules; // <moduleCode+Year,ModuleInstance>, cant have a map of references

public:
    Student();
    Student(unsigned int StudentNumber, unsigned int YearOfStudy, unsigned int enrollmentYear, Person &person);
    unsigned int getStudentNumber();
    unsigned int getYearOfStudy();
    unsigned int getenrollmentYear();
    void setYearOfStudy(unsigned int i);
    void setEnrollmentYear(unsigned int i);
    bool passYear(unsigned int Year);
    vector<ModuleInstance> getModules();
    vector<ModuleInstance> getModules(unsigned int Year);
    void addModule(ModuleInstance *ModuleInstance_);
    void removeModule(ModuleInstance *ModuleInstance_);
    float getGPA();
};

#endif