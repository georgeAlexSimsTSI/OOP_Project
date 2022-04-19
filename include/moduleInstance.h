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

class moduleInstance
{
private:
    professor *professor_;
    vector<assignment> assignments;
    unsigned int year;
    module_ module__;

public:
    moduleInstance();
    moduleInstance(professor &professor_, vector<assignment> assignments, unsigned int year, module_ module__);
    professor *getProfessor();
    void setProfessor(professor *professor_);

    unsigned int getYear();
    module_ &getModule();

    void giveGrade(unsigned int studentNum, string assignmentCode, float score);
    void setAssignment(vector<assignment> &assignments);
    void addAssignment(assignment &assignment_);
    void addAssignment(string code, string desc);

    vector<assignment> &getAssignments();
    assignment &getAssignment(string code);
    float getStudentAverage(unsigned int studentNum);
};

#endif