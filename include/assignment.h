#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

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
    assignment(string code, string desc);
    void giveGrade(unsigned int studentNumber, float score);
    float getGrade(unsigned int studentNum);
    map<int, float> &getGrades();
    string getCode() const;
    void setCode(string code);
    string getDesc() const;
    void setDesc(string desc);
};

#endif