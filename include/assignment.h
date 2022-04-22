#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include <map>
#include <stdexcept>
using std::map;
using std::string;

/**
 * @brief Data storage class that represents an Assignment for a course
 */

class Assignment
{
private:
    string code;
    string desc;
    map<unsigned int, float> grades; // <StudentNumber,gradePercent>

public:
    Assignment();
    Assignment(string code, string desc);
    void giveGrade(unsigned int StudentNumber, float score);
    float getGrade(unsigned int StudentNum);
    map<unsigned int, float> &getGrade();
    string getCode() const;
    void setCode(string code);
    string getDesc() const;
    void setDesc(string desc);
};

#endif