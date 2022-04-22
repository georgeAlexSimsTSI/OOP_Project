#ifndef Year_H
#define Year_H

#include "student.h"
#include "professor.h"
#include "moduleInstance.h"
#include <stdexcept>
#include <vector>
using std::domain_error;
using std::vector;

/**
 * @brief class that stores the available modules for this Year, the enrolled students, professors and the active modules
 */
class Year
{
private:
    unsigned int year;
    vector<Student *> students;           // vector of Student pointers
    vector<Professor *> professors;       // vector of Professor pointers
    vector<ModuleInstance> activeModules; // vector of module instances

public:
    Year();
    Year(unsigned int year, vector<Student *> students, vector<Professor *> professors, vector<ModuleInstance> activeModules);
    unsigned int getYear();
    void setYear(unsigned int year);
    vector<Student *> &getstudents();
    void setstudents(vector<Student *> students);
    void addStudent(Student *student);
    vector<Professor *> &getprofessors();
    void setprofessors(vector<Professor *> professors);
    void addProfessor(Professor *professor);
    vector<ModuleInstance> &getActiveModules();
    void setActiveModules(vector<ModuleInstance> activeModules_);
    void addActiveModule(ModuleInstance activeModule);
    ModuleInstance &getActiveModule(string moduleCode); // Throws domain exception if not found

    void removeModuleInstance(string code);
    void removeStudent(unsigned int StudentNum);
    void removeProfessor(unsigned int staffNum, Professor *replacement);
};

#endif