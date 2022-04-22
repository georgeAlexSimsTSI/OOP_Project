#include "../include/system.h"

UniSystem::UniSystem()
{
    this->years = map<unsigned int, Year>();
    this->students = map<unsigned int, Student>();
    this->professors = map<unsigned int, Professor>();
}

UniSystem::UniSystem(map<unsigned int, Student> students, map<unsigned int, Professor> professors, map<unsigned int, Year> years)
{
    this->years = years;
    this->students = students;
    this->professors = professors;
}

void UniSystem::addStudent(Student student)
{
    this->students[student.getStudentNumber()] = student;
}

void UniSystem::addProfessor(Professor professor)
{
    this->professors[professor.getStaffNumber()] = professor;
}

void UniSystem::addYear(Year year)
{
    this->years[year.getYear()] = year;
}

Student &UniSystem::getStudent(unsigned int StudentNum)
{
    if (students.find(StudentNum) == students.end())
        throw std::domain_error("No such Student");
    return students[StudentNum];
}

map<unsigned int, Student> &UniSystem::getStudent()
{

    return this->students;
}

Professor &UniSystem::getProfessor(unsigned int staffNum)
{
    if (professors.find(staffNum) == professors.end())
        throw std::domain_error("No such Professor");
    return professors[staffNum];
}

map<unsigned int, Professor> &UniSystem::getProfessor()
{
    return this->professors;
}

Year &UniSystem::getYear(unsigned int year)
{
    if (years.find(year) == years.end())
        throw std::domain_error("No such Year");
    return years[year];
}

map<unsigned int, Year> &UniSystem::getYear()
{
    return this->years;
}

void UniSystem::removeAssignment(unsigned int year, string moduleCode, string AssignmentCode) // must remove from the ModuleInstance, that is all
{
    Year *y = &getYear(year);
    ModuleInstance *m = &y->getActiveModule(moduleCode);
    vector<Assignment> *assignments = &m->getassignments();
    int i = 0;
    bool found = false;
    for (; i < assignments->size(); ++i)
    {
        if ((*assignments)[i].getCode() == AssignmentCode)
        {
            found = true;
            break;
        }
    }
    if (!found)
        throw std::domain_error("No such Assignment");
    (*assignments).erase((*assignments).begin() + i);
}

void UniSystem::removeModuleInstance(unsigned int year, string moduleCode) // must remove from Year and students
{
    ModuleInstance *m = &getYear(year).getActiveModule(moduleCode);
    vector<Student *> *yearstudents = &getYear(year).getstudents();
    for (int i = 0; i < yearstudents->size(); ++i)
    {
        getStudent(yearstudents->at(i)->getStudentNumber()).removeModule(m);
    }
    getYear(year).removeModuleInstance(moduleCode);
}

void UniSystem::removeStudent(unsigned int StudentNumber) // remove from years, ModuleInstances + assignments
{
    for (auto &i : years)
    {
        i.second.removeStudent(StudentNumber);
    }

    for (auto &i : getStudent(StudentNumber).getModules())
    {
        ModuleInstance *m = &years[i.getYear()].getActiveModule(i.getModule().getModuleCode());
        for (auto &j : m->getassignments())
        {
            j.getGrade().erase(StudentNumber);
        }
    }
    students.erase(StudentNumber);
}

void UniSystem::removeProfessor(unsigned int staffNumber, unsigned int replacement) // remove from years, ModuleInstance, must replace Professor with another one
{
    Professor *toRemove = &getProfessor(staffNumber), *replacementProf = &getProfessor(replacement);
    for (auto &i : years)
    {
        i.second.removeProfessor(staffNumber, replacementProf);
    }
}

void UniSystem::removeYear(unsigned int year) // remove all ModuleInstances from students, then remove the Year
{
    vector<ModuleInstance> *modules = &getYear(year).getActiveModules();
    for (int i = 0; i < modules->size(); ++i)
    {
        removeModuleInstance(year, (*modules)[i].getModule().getModuleCode());
        i--;
    }
    years.erase(year);
}