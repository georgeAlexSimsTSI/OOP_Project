#include "../include/system.h"

uniSystem::uniSystem()
{
    this->years = map<unsigned int, year>();
    this->students = map<unsigned int, student>();
    this->professors = map<unsigned int, professor>();
}

uniSystem::uniSystem(map<unsigned int, student> students, map<unsigned int, professor> professors, map<unsigned int, year> years)
{
    this->years = years;
    this->students = students;
    this->professors = professors;
}

void uniSystem::addStudent(student student_)
{
    this->students[student_.getStudentNumber()] = student_;
}

void uniSystem::addProfessor(professor professor_)
{
    this->professors[professor_.getStaffNumber()] = professor_;
}

void uniSystem::addYear(year year_)
{
    this->years[year_.getYear()] = year_;
}

student &uniSystem::getStudent(unsigned int studentNum)
{
    if (students.find(studentNum) == students.end())
        throw std::domain_error("No such student");
    return students[studentNum];
}

map<unsigned int, student> &uniSystem::getStudent()
{

    return this->students;
}

professor &uniSystem::getProfessor(unsigned int staffNum)
{
    if (professors.find(staffNum) == professors.end())
        throw std::domain_error("No such Professor");
    return professors[staffNum];
}

map<unsigned int, professor> &uniSystem::getProfessor()
{
    return this->professors;
}

year &uniSystem::getYear(unsigned int year_)
{
    if (years.find(year_) == years.end())
        throw std::domain_error("No such Year");
    return years[year_];
}

map<unsigned int, year> &uniSystem::getYear()
{
    return this->years;
}