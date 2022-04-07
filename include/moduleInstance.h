#ifndef MODULEINSTANCE_H
#define MODULEINSTANCE_H

#include "student.h"
#include "professor.h"
#include "assignment.h"
#include "module.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class moduleInstance
{
private:
    professor professor_;
    vector<student> students;
    vector<assignment> assignments;
    unsigned int year;
    module_ module_;

public:
    moduleInstance(professor &professor_, string subject, unsigned int roomNum);
    moduleInstance(moduleInstance &moduleInstance_);
};

#endif