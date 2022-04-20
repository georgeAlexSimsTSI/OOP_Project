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

void uniSystem::removeAssignment(unsigned int year_, string moduleCode, string assignmentCode) // must remove from the ModuleInstance, that is all
{
    year *y = &getYear(year_);
    moduleInstance *m = &y->getActiveModule(moduleCode);
    vector<assignment> *assignments = &m->getAssignments();
    int i = 0;
    bool found = false;
    for (; i < assignments->size(); ++i)
    {
        if ((*assignments)[i].getCode() == assignmentCode)
        {
            found = true;
            break;
        }
    }
    if (!found)
        throw std::domain_error("No such assignment");
    (*assignments).erase((*assignments).begin() + i);
}

void uniSystem::removeModuleInstance(unsigned int year_, string moduleCode) // must remove from year and students
{
    moduleInstance *m = &getYear(year_).getActiveModule(moduleCode);
    vector<student *> *yearStudents = &getYear(year_).getStudents();
    for (int i = 0; i < yearStudents->size(); ++i)
    {
        getStudent(yearStudents->at(i)->getStudentNumber()).removeModule(m);
    }
    getYear(year_).removeModuleInstance(moduleCode);
}

void uniSystem::removeStudent(unsigned int studentNumber) // remove from years, ModuleInstances + Assignments
{
    for (auto &i : years)
    {
        i.second.removeStudent(studentNumber);
    }

    for (auto &i : getStudent(studentNumber).getModules())
    {
        moduleInstance *m = &years[i.getYear()].getActiveModule(i.getModule().getModuleCode());
        for (auto &j : m->getAssignments())
        {
            j.getGrades().erase(studentNumber);
        }
    }
    students.erase(studentNumber);
}

void uniSystem::removeProfessor(unsigned int staffNumber, unsigned int replacement) // remove from years, ModuleInstance, must replace professor with another one
{
    professor *toRemove = &getProfessor(staffNumber), *replacementProf = &getProfessor(replacement);
    for (auto &i : years)
    {
        i.second.removeProfessor(staffNumber, replacementProf);
    }
}

void uniSystem::removeYear(unsigned int year_) // remove all moduleInstances from students, then remove the year
{
    vector<moduleInstance> *modules = &getYear(year_).getActiveModules();
    for (int i = 0; i < modules->size(); ++i)
    {
        removeModuleInstance(year_, (*modules)[i].getModule().getModuleCode());
        i--;
    }
    years.erase(year_);
}