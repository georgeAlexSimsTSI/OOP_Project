#include "../include/moduleInstance.h"

moduleInstance::moduleInstance()
{
    this->professor_ = professor();
    this->students = vector<student>();
    this->assignments = vector<assignment>();
    this->module__ = module_();
    this->year = 0u;
}

moduleInstance::moduleInstance(moduleInstance &moduleInstance_)
{
    this->professor_ = moduleInstance_.professor_;
    this->students = moduleInstance_.students;
    this->assignments = moduleInstance_.assignments;
    this->module__ = moduleInstance_.module__;
    this->year = moduleInstance_.year;
}

moduleInstance::moduleInstance(professor &professor_, vector<student> students, vector<assignment> assignments, unsigned int year, module_ module__)
{
    this->professor_ = professor_;
    this->students = students;
    this->assignments = assignments;
    this->year = year;
    this->module__ = module__;
}

professor &moduleInstance::getProfessor()
{
    return this->professor_;
}

void moduleInstance::setProfessor(professor &professor_)
{
    this->professor_ = professor_;
}

vector<student> &moduleInstance::getStudents()
{
    return this->students;
}

void moduleInstance::setStudents(vector<student> &students)
{
    this->students = students;
}

student &moduleInstance::getStudent(unsigned int studentNum) throw()
{
    for (auto &i : this->students)
    {
        if (i.getStudentNumber() == studentNum)
        {
            return i;
        }
    }
    throw std::domain_error("No such student");
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

float moduleInstance::getStudentAverage(unsigned int studentNum)
{
    // check if student is in module
    bool studentFound = false;
    for (auto it : students)
    {
        if (it.getStudentNumber() == studentNum)
        {
            studentFound = true;
            break;
        }
    }

    if (!studentFound)
        return 0.0f;

    float sum = 0.0f;
    for (auto it : this->assignments)
    {
        sum += it.getGrade(studentNum);
    }

    // if a student hasn't done an assignment then they get 0;

    return (sum / this->assignments.size());
}
