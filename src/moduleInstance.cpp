#include "../include/ModuleInstance.h"

ModuleInstance::ModuleInstance() : module_(Module())
{
    this->professor = nullptr;
    this->assignments = vector<Assignment>();
    year = 0u;
}

ModuleInstance::ModuleInstance(Professor &professor, const vector<Assignment> &assignments, const unsigned int &year, const Module &module_) : professor(&professor), assignments(assignments), year(year), module_(module_)
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

void ModuleInstance::setAssignment(const vector<Assignment> &assignments)
{
    this->assignments = assignments;
}

void ModuleInstance::addAssignment(const Assignment &assignment)
{
    this->assignments.push_back(assignment);
}

void ModuleInstance::addAssignment(const string &code, const string &desc)
{
    Assignment assignment = Assignment(code, desc);
    this->assignments.push_back(assignment);
}

Module &ModuleInstance::getModule()
{
    return this->module_;
}

unsigned int ModuleInstance::getYear() const
{
    return this->year;
}

void ModuleInstance::giveGrade(const unsigned int &StudentNum, const string &assignmentCode, const float &score)
{
    auto it = std::find(assignments.begin(), assignments.end(), assignmentCode);
    if (it != this->assignments.end())
    {
        it->giveGrade(StudentNum, score);
    }
}

float ModuleInstance::getStudentAverage(const unsigned int &studentNum)
{
    float sum = 0.0f;
    for (auto it : this->assignments)
    {
        sum += it.getGrade(studentNum);
    }

    return (sum / this->assignments.size());
}

Assignment &ModuleInstance::getAssignment(const string &code)
{
    auto it = std::find(assignments.begin(), assignments.end(), code);
    if (it != this->assignments.end())
    {
        return *it;
    }
    throw std::domain_error("No Assignment with that code");
}