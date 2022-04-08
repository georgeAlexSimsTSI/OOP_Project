#ifndef SYSTEM_H
#define SYSTEM_H

#include "student.h"
#include "professor.h"
#include "year.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

/**
 * @brief class that holds all of the years, students and professor objects and provides methods to get and modify, CRUD 
 */
class uniSystem{
    private:
        vector<year> years;
        vector<student> students;
        vector<professor> professors;
    public:
        uniSystem();
        uniSystem(vector<student> students, vector<professor> professors, vector<year> years);
        void addStudent();
        void addStudent(student student_);
        void addProfessor();
        void addProfessor(professor professor);
        void addYear();
        void addYear(year year_);
        student &getStudent(unsigned int studentNum);
        vector<student> &getStudent();
        professor &getProfessor(unsigned int staffNum);
        vector<professor> &getProfessor();
        year &getYear(unsigned int year_);
        vector<year> &getYear();



};

#endif