#include "../include/moduleInstance.h"

moduleInstance::moduleInstance()
{
    // this->professor_ = professor();
    this->assignments = vector<assignment>();
    year = 0u;
    module__ = module_();
}

moduleInstance::moduleInstance(professor &professor_, vector<assignment> assignments, unsigned int year, module_ module__) : professor_(&professor_), assignments(assignments), year(year), module__(module__)
{
}

professor *moduleInstance::getProfessor()
{
    return this->professor_;
}

void moduleInstance::setProfessor(professor *professor_)
{
    this->professor_ = professor_;
}

vector<assignment> &moduleInstance::getAssignments()
{
    return this->assignments;
}

void moduleInstance::setAssignment(vector<assignment> &assignments)
{
    this->assignments = assignments;
}

void moduleInstance::addAssignment(assignment &assignment_)
{
    this->assignments.push_back(assignment_);
}

void moduleInstance::addAssignment(string code, string desc)
{
    assignment assignment_ = assignment(code, desc);
    this->assignments.push_back(assignment_);
}

module_ &moduleInstance::getModule()
{
    return this->module__;
}

unsigned int moduleInstance::getYear()
{
    return this->year;
}

void moduleInstance::giveGrade(unsigned int studentNum, string assignmentCode, float score)
{
    for (auto &i : this->assignments)
    {
        if (i.getCode() == assignmentCode)
        {
            i.giveGrade(studentNum, score);
            return;
        }
    }
    // undecided on if this should throw an exception or not
}

float moduleInstance::getStudentAverage(unsigned int studentNum)
{
    float sum = 0.0f;
    for (auto it : this->assignments)
    {
        sum += it.getGrade(studentNum);
    }

    return (sum / this->assignments.size());
}

assignment &moduleInstance::getAssignment(string code)
{
    for (auto &i : this->assignments)
    {
        if (i.getCode() == code)
        {
            return i;
        }
    }
    throw std::domain_error("No assignment with that code");
}