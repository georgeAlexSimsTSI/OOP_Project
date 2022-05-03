#include "../include/Year.h"

// Year::~Year(){
//     // delete modules;
// }

class MyException : public std::exception
{
    std::string code;

public:
    explicit MyException(const std::string &code) : code(code)
    {
    }
    const char *what() const throw()
    {
        return "Custom Exception";
    }
};

Year::Year()
{
    this->year = 0u;
    // this->modules = vector<Module>();
    this->students = vector<Student *>();
    this->professors = vector<Professor *>();
    this->activeModules = vector<ModuleInstance>();
}

Year::Year(const unsigned int &year, const vector<Student *> &students, const vector<Professor *> &professors, const vector<ModuleInstance> &activeModules)
{
    this->year = year;
    // this->modules = modules;
    this->students = students;
    this->professors = professors;
    this->activeModules = activeModules;
}

unsigned int Year::getYear() const
{
    return this->year;
}

void Year::setYear(const unsigned int &year)
{
    this->year = year;
}

vector<Student *> &Year::getstudents()
{
    return this->students;
}

void Year::setstudents(const vector<Student *> &students)
{
    this->students = students;
}

void Year::addStudent(Student *student)
{
    this->students.push_back(student);
}

// vector<Module> Year::getModule()
// {
//     return this->modules;
// }

// void Year::setModules(vector<Module> modules)
// {
//     //delete modules;
//     this->modules = modules;
// }

// void Year::addModule(Module module_)
// {
//     this->modules.push_back(module_);
// }

vector<Professor *> &Year::getprofessors()
{
    return this->professors;
}

void Year::setprofessors(const vector<Professor *> &professors)
{
    this->professors = professors;
}

void Year::addProfessor(Professor *professor)
{
    this->professors.push_back(professor);
}

vector<ModuleInstance> &Year::getActiveModules()
{
    return this->activeModules;
}

void Year::setActiveModules(const vector<ModuleInstance> &activeModules_)
{
    this->activeModules = activeModules_;
}

void Year::addActiveModule(const ModuleInstance &activeModule)
{
    this->activeModules.push_back(activeModule);
}

// moduleCode should be uppercase
ModuleInstance &Year::getActiveModule(const string &moduleCode)
{
    for (auto &i : this->activeModules)
    {
        if (i.getModule().getModuleCode() == moduleCode)
        {
            return i;
        }
    }
    //throw MyException(moduleCode); //throwing a custom exception
    throw std::domain_error("No such active module: " + moduleCode);
}

void Year::removeModuleInstance(const string &code)
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

void Year::removeStudent(const unsigned int &StudentNum)
{
    // Just remove from the Year, the Student will be removed from the assignments somewhere else
    for (int i = 0; i < students.size(); ++i)
    {
        if (students[i]->getStudentNumber() == StudentNum)
        {
            students.erase(students.begin() + i);
            break;
        }
    }
}

void Year::removeProfessor(const unsigned int &staffNum, Professor *replacement) // Yeah re do this later
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
        if (!found && (professors[i]->getStaffNumber() == replacement->getStaffNumber()))
        {
            found = true;
            replacement = professors[i];
        }
    }
    // need to iterate through each module instance and check

    if (!found)
        addProfessor(replacement);

    for (auto &i : activeModules)
    {
        if (i.getProfessor()->getStaffNumber() == staffNum)
        {
            i.setProfessor(replacement);
        }
    }

    professors.erase(professors.begin() + removeIndex);
}
