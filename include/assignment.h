#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "student.h"
#include <string>
#include <map>
using std::map;
using std::string;

class assignment
{
private:
    string code;
    string desc;
    map<int, float> grades;

public:
    assignment(string code, string desc);
    bool giveGrade(student &student_, float score);
    map<int, float> &getGrades();
    string getCode() const;
    string getDesc() const;
    string getString() const;
};

#endif