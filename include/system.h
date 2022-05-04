#ifndef SYSTEM_H
#define SYSTEM_H

#include "student.h"
#include "professor.h"
#include "year.h"
#include <string>
#include <vector>
#include <stdexcept>
using std::string;
using std::vector;

/**
 * @brief class that holds all of the years, students and Professor objects
 * add new objects
 * access references to the objects so that they can be modified outside of this class.
 *
 * if time permitted will add option to delete objects
 *  this will require me to be thorough to remove all references to it
 *  e.g. removing a Student means I will have to check each Year and module instance
 */
class UniSystem
{
private:
    map<unsigned int, Student> *students;     // list of all students past and present
    map<unsigned int, Professor> *professors; // list of all professors past and present
    map<unsigned int, Year> *years;           // contains the active modules of each Year and participating students

public:
    // UniSystem();
    ~UniSystem();
    UniSystem(map<unsigned int, Student> &students, map<unsigned int, Professor> &professors, map<unsigned int, Year> &years);
    UniSystem(map<unsigned int, Student> *students, map<unsigned int, Professor> *professors, map<unsigned int, Year> *years);
    void addStudent(const Student &student);
    void addProfessor(const Professor &professor);
    void addYear(const Year &year);

    // this method if you want to modify a Student
    Student &getStudent(const unsigned int &StudentNum);
    map<unsigned int, Student> &getStudent();

    // this method if you want to modify a Professor
    Professor &getProfessor(const unsigned int &staffNum);
    map<unsigned int, Professor> &getProfessor();

    // this method if you want to modify a Year
    Year &getYear(const unsigned int &year);
    map<unsigned int, Year> &getYear();

    // remove methods
    void removeAssignment(const unsigned int &year, const string &moduleCode, const string &AssignmentCode); // must remove from the ModuleInstance, that is all
    void removeModuleInstance(const unsigned int &year, const string &moduleCode);                           // must remove from Year and students
    void removeStudent(const unsigned int &StudentNumber);                                                   // remove from years, ModuleInstances + assignments
    void removeProfessor(const unsigned int &staffNumber, const unsigned int &replacement);                  // remove from years, ModuleInstance, must replace Professor with another one
    void removeYear(const unsigned int &year);                                                               // remove all ModuleInstances from students, then remove the Year
};

#endif