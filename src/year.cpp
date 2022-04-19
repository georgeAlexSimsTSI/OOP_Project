#include "../include/year.h"

// year::~year(){
//     // delete modules;
// }

year::year()
{
    this->year_ = 0u;
    // this->modules = vector<module_>();
    this->students = vector<student *>();
    this->professors = vector<professor *>();
    this->activeModules = vector<moduleInstance>();
}

year::year(unsigned int year_, vector<student *> students, vector<professor *> professors, vector<moduleInstance> activeModules)
{
    this->year_ = year_;
    // this->modules = modules;
    this->students = students;
    this->professors = professors;
    this->activeModules = activeModules;
}

unsigned int year::getYear()
{
    return this->year_;
}

void year::setYear(unsigned int year_)
{
    this->year_ = year_;
}

vector<student *> &year::getStudents()
{
    return this->students;
}

void year::setStudents(vector<student *> students)
{
    this->students = students;
}

void year::addStudent(student *student_)
{
    this->students.push_back(student_);
}

// vector<module_> year::getModule()
// {
//     return this->modules;
// }

// void year::setModules(vector<module_> modules)
// {
//     //delete modules;
//     this->modules = modules;
// }

// void year::addModule(module_ module__)
// {
//     this->modules.push_back(module__);
// }

vector<professor *> &year::getProfessors()
{
    return this->professors;
}

void year::setProfessors(vector<professor *> professors)
{
    this->professors = professors;
}

void year::addProfessor(professor *professor_)
{
    this->professors.push_back(professor_);
}

vector<moduleInstance> &year::getActiveModules()
{
    return this->activeModules;
}

void year::setActiveModules(vector<moduleInstance> activeModules_)
{
    this->activeModules = activeModules_;
}

void year::addActiveModule(moduleInstance activeModule)
{
    this->activeModules.push_back(activeModule);
}

// moduleCode should be uppercase
moduleInstance &year::getActiveModule(string moduleCode)
{
    for (auto &i : this->activeModules)
    {
        if (i.getModule().getModuleCode() == moduleCode)
        {
            return i;
        }
    }
    throw std::domain_error("No such active module");
}

void year::removeModuleInstance(string code)
{
    for (int i = 0; i < activeModules.size(); ++i)
    {
        if ((activeModules[i]).getModule().getModuleCode() == code)
        {
            activeModules.erase(activeModules.begin() + i);
            break;
        }
    }
}

void year::removeStudent(unsigned int studentNum)
{
    // Just remove from the year, the student will be removed from the assignments somewhere else
    for (int i = 0; i < students.size(); ++i)
    {
        if (students[i]->getStudentNumber() == studentNum)
        {
            students.erase(students.begin() + i);
            break;
        }
    }
}

void year::removeProfessor(unsigned int staffNum, professor * replacement) // Yeah re do this later
{
    if (staffNum == replacement->getStaffNumber())
        return;

    bool found = false;
    int removeIndex = -1;
    for (int i = 0; (i < professors.size()) && (removeIndex == -1 || !found); ++i)
    {
        if (removeIndex == -1 && (professors[i]->getStaffNumber() == staffNum))
        {
            removeIndex = i;
        }
        if(!found && (professors[i]->getStaffNumber() == replacement->getStaffNumber()) ){
            found = true;
            replacement = professors[i];
        }
    }
    // need to iterate through each module instance and check

    if(!found)
        addProfessor(replacement);

    for (auto &i : activeModules)
    {
        if (i.getProfessor()->getStaffNumber() == staffNum)
        {
            i.setProfessor(replacement);
        }
    }
}
