#include "../include/ModuleInstance.h"

ModuleInstance::ModuleInstance()
{
    // this->professor = Professor();
    this->assignments = vector<Assignment>();
    year = 0u;
    module_ = Module();
}

ModuleInstance::ModuleInstance(Professor &professor, vector<Assignment> assignments, unsigned int year, Module module_) : professor(&professor), assignments(assignments), year(year), module_(module_)
{
}

Professor *ModuleInstance::getProfessor()
{
    return this->professor;
}

void ModuleInstance::setProfessor(Professor *professor)
{
    this->professor = professor;
}

vector<Assignment> &ModuleInstance::getassignments()
{
    return this->assignments;
}

void ModuleInstance::setAssignment(vector<Assignment> &assignments)
{
    this->assignments = assignments;
}

void ModuleInstance::addAssignment(Assignment &assignment)
{
    this->assignments.push_back(assignment);
}

void ModuleInstance::addAssignment(string code, string desc)
{
    Assignment assignment = Assignment(code, desc);
    this->assignments.push_back(assignment);
}

Module &ModuleInstance::getModule()
{
    return this->module_;
}

unsigned int ModuleInstance::getYear()
{
    return this->year;
}

void ModuleInstance::giveGrade(unsigned int StudentNum, string AssignmentCode, float score)
{
    for (auto &i : this->assignments)
    {
        if (i.getCode() == AssignmentCode)
        {
            i.giveGrade(StudentNum, score);
            return;
        }
    }
    // undecided on if this should throw an exception or not
}

float ModuleInstance::getStudentAverage(unsigned int StudentNum)
{
    float sum = 0.0f;
    for (auto it : this->assignments)
    {
        sum += it.getGrade(StudentNum);
    }

    return (sum / this->assignments.size());
}

Assignment &ModuleInstance::getAssignment(string code)
{
    for (auto &i : this->assignments)
    {
        if (i.getCode() == code)
        {
            return i;
        }
    }
    throw std::domain_error("No Assignment with that code");
}