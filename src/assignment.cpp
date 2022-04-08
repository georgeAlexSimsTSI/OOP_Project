#include "../include/assignment.h"

assignment::assignment(){
    code = "";
    desc = "";
}

assignment::assignment(string code, string desc)
{
    this->code = code;
    this->desc = desc;
}

assignment::assignment(assignment &assignment_) : assignment(assignment_.code, assignment_.desc)
{
}

void assignment::giveGrade(student &student_, float score)
{
    this->grades[student_.getStudentNumber()] = score;
}

float assignment::getGrade(student &student_){
    auto it = this->grades.find(student_.getStudentNumber());
    if(it == this->grades.end())
        //throw std::domain_error("Student is ungraded")
        return -1.00f;
    return this->grades.at(student_.getStudentNumber());
}

map<int, float> &assignment::getGrades()
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

string assignment::getString() const
{
    return this->code + " :" + this->desc + " with:" + std::to_string(this->grades.size()) + " grades";
}