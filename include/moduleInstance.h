#ifndef MODULEINSTANCE_H
#define MODULEINSTANCE_H

#include "professor.h"
#include "assignment.h"
#include "module.h"
#include <string>
#include <vector>
#include <stdexcept>

using std::domain_error;
using std::string;
using std::vector;

class ModuleInstance
{
private:
    Professor *professor;
    vector<Assignment> assignments;
    unsigned int year;
    Module module_;

public:
    ModuleInstance();
    ModuleInstance(Professor &professor, vector<Assignment> assignments, unsigned int year, Module module_);
    Professor *getProfessor();
    void setProfessor(Professor *professor);

    unsigned int getYear();
    Module &getModule();

    void giveGrade(unsigned int StudentNum, string assignmentCode, float score);
    void setAssignment(vector<Assignment> &assignments);
    void addAssignment(Assignment &assignment);
    void addAssignment(string code, string desc);

    vector<Assignment> &getassignments();
    Assignment &getAssignment(string code);
    float getStudentAverage(unsigned int StudentNum);
};

#endif