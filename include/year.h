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
    Year(const unsigned int &year, const vector<Student *> &students, const vector<Professor *> &professors, const vector<ModuleInstance> &activeModules);
    unsigned int getYear();
    void setYear(const unsigned int &year);
    vector<Student *> &getstudents();
    void setstudents(const vector<Student *> &students);
    void addStudent(Student *student);
    vector<Professor *> &getprofessors();
    void setprofessors(const vector<Professor *> &professors);
    void addProfessor(Professor *professor);
    vector<ModuleInstance> &getActiveModules();
    void setActiveModules(const vector<ModuleInstance> &activeModules_);
    void addActiveModule(const ModuleInstance &activeModule);
    ModuleInstance &getActiveModule(const string &moduleCode); // Throws domain exception if not found

    void removeModuleInstance(const string &code);
    void removeStudent(const unsigned int &StudentNum);
    void removeProfessor(const unsigned int &staffNum, Professor *replacement);
};

#endif