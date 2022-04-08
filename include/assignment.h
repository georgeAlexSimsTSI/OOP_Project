#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "student.h"
#include <string>
#include <map>
#include <stdexcept>
using std::map;
using std::string;

/**
 * @brief Data storage class that represents an assignment for a course 
 */
class assignment
{
private:
    string code;
    string desc;
    map<int, float> grades; // <studentNumber,gradePercent>

public:
    assignment();    
    assignment(assignment &assignment_);
    assignment(string code, string desc);
    void giveGrade(student &student_, float score); //if the student already has a grade just override it
    float getGrade(student &student_);
    map<int, float> &getGrades();
    string getCode() const;
    void setCode(string code);
    string getDesc() const;
    void setDesc(string desc);
    string getString() const;
};

#endif