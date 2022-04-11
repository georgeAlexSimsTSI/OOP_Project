#ifndef YEAR_H
#define YEAR_H

#include "student.h"
#include "professor.h"
#include "moduleInstance.h"
#include <stdexcept>
#include <vector>
using std::vector;
using std::domain_error;

/**
 * @brief class that stores the available modules for this year, the enrolled students, professors and the active modules
 */
class year
{
private:
    unsigned int year_;
    vector<module_> *modules; //pointer to a module vector
    vector<student*> students;//vector of student pointers
    vector<professor*> professors;//vector of professor pointers
    vector<moduleInstance> activeModules;//vector of module instances

public:
    ~year();
    year();
    year(unsigned int year_, vector<module_> *modules, vector<student*> students, vector<professor*> professors, vector<moduleInstance> activeModules);
    unsigned int getYear();
    void setYear(unsigned int year_);
    vector<student*> &getStudents();
    void setStudents(vector<student*> students);
    void addStudent(student *student_);
    vector<module_> *getModule();
    void setModules(vector<module_> *modules);
    void addModule(module_ module__);
    vector<professor*> &getProfessors();
    void setProfessors(vector<professor*> professors);
    void addProfessor(professor *professor_);
    vector<moduleInstance> &getActiveModules();
    void setActiveModules(vector<moduleInstance> activeModules_);
    void addActiveModule(moduleInstance activeModule);
    moduleInstance &getActiveModule(string moduleCode) throw();
};

#endif