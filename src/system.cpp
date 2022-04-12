#include "../include/system.h"

uniSystem::uniSystem()
{
    this->years = vector<year>();
    this->students = vector<student>();
    this->professors = vector<professor>();
}

uniSystem::uniSystem(vector<student> students, vector<professor> professors, vector<year> years)
{
    this->years = years;
    this->students = students;
    this->professors = professors;
}

void uniSystem::addStudent(student student_)
{
    this->students.push_back(student_);
}

void uniSystem::addProfessor(professor professor_)
{
    this->professors.push_back(professor_);
}

void uniSystem::addYear(year year_)
{
    this->years.push_back(year_);
}

student &uniSystem::getStudent(unsigned int studentNum) throw()
{
    for (auto &i : this->students)
    {
        if (i.getStudentNumber() == studentNum)
            return i;
    }
    throw std::domain_error("No such student");
}

vector<student> &uniSystem::getStudent()
{
    return this->students;
}

professor &uniSystem::getProfessor(unsigned int staffNum) throw()
{
    for (auto &i : this->professors)
    {
        if (i.getStaffNumber() == staffNum)
            return i;
    }
    throw std::domain_error("No such Professor");
}

vector<professor> &uniSystem::getProfessor()
{
    return this->professors;
}

year &uniSystem::getYear(unsigned int year_) throw()
{
    for (auto &i : this->years)
    {
        if (i.getYear() == year_)
            return i;
    }
    throw std::domain_error("No such Year");
}

vector<year> &uniSystem::getYear()
{
    return this->years;
}