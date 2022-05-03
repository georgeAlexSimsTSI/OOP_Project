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
    ModuleInstance(Professor &professor, const vector<Assignment> &assignments, const unsigned int &year, const Module &module_);
    Professor *getProfessor();
    void setProfessor(Professor *professor);

    unsigned int getYear() const;
    Module &getModule();

    void giveGrade(const unsigned int &StudentNum, const string &assignmentCode, const float &score);
    void setAssignment(const vector<Assignment> &assignments);
    void addAssignment(const Assignment &assignment);
    void addAssignment(const string &code, const string &desc);

    vector<Assignment> &getassignments();
    Assignment &getAssignment(const string &code);
    float getStudentAverage(const unsigned int &studentNum);
};

#endif