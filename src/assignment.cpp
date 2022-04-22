#include "../include/Assignment.h"

Assignment::Assignment()
{
    code = "";
    desc = "";
}

Assignment::Assignment(string code, string desc)
{
    this->code = code;
    this->desc = desc;
}

void Assignment::giveGrade(unsigned int StudentNumber, float score)
{
    this->grades[StudentNumber] = score;
}

float Assignment::getGrade(unsigned int StudentNum)
{
    auto it = this->grades.find(StudentNum);
    if (it == this->grades.end())
        // throw std::domain_error("Student is ungraded")
        return -1.00f;
    return this->grades.at(StudentNum);
}

map<unsigned int, float> &Assignment::getGrade()
{
    return this->grades;
}

string Assignment::getCode() const
{
    return this->code;
}

void Assignment::setCode(string code)
{
    this->code = code;
}

string Assignment::getDesc() const
{
    return this->desc;
}

void Assignment::setDesc(string desc)
{
    this->desc = desc;
}