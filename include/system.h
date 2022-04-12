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
 * @brief class that holds all of the years, students and professor objects
 * add new objects
 * access references to the objects so that they can be modified outside of this class.
 *
 * if time permitted will add option to delete objects
 *  this will require me to be thorough to remove all references to it
 *  e.g. removing a student means I will have to check each year and module instance
 */
class uniSystem
{
private:
    vector<year> years;           // contains the active modules of each year and participating students
    vector<student> students;     // list of all students past and pressent
    vector<professor> professors; // list of all professors past and pressent

public:
    uniSystem();
    uniSystem(vector<student> students, vector<professor> professors, vector<year> years);
    void addStudent(student student_);
    void addProfessor(professor professor_);
    void addYear(year year_);

    // this method if you want to modify a student
    student &getStudent(unsigned int studentNum) throw();
    vector<student> &getStudent();

    // this method if you want to modify a professor
    professor &getProfessor(unsigned int staffNum) throw();
    vector<professor> &getProfessor();

    // this method if you want to modify a year
    year &getYear(unsigned int year_) throw();
    vector<year> &getYear();
};

#endif