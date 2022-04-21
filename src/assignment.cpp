#include "../include/assignment.h"

assignment::assignment()
{
    code = "";
    desc = "";
}

assignment::assignment(string code, string desc)
{
    this->code = code;
    this->desc = desc;
}

void assignment::giveGrade(unsigned int studentNumber, float score)
{
    this->grades[studentNumber] = score;
}

float assignment::getGrade(unsigned int studentNum)
{
    auto it = this->grades.find(studentNum);
    if (it == this->grades.end())
        // throw std::domain_error("Student is ungraded")
        return -1.00f;
    return this->grades.at(studentNum);
}

map<int, float> &assignment::getGrade()
{
    return this->grades;
}

string assignment::getCode() const
{
    return this->code;
}

void assignment::setCode(string code)
{
    this->code = code;
}

string assignment::getDesc() const
{
    return this->desc;
}

void assignment::setDesc(string desc)
{
    this->desc = desc;
}