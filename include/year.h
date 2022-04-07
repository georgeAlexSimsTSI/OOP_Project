#ifndef YEAR_H
#define YEAR_H

#include "student.h"
#include "professor.h"
#include "moduleInstance.h"

#include <vector>
using std::vector;

class year{
    private:
        unsigned int year;
        vector<module_> modules;
        vector<student> students;
        vector<professor> professors;
        vector<moduleInstance> activeModules;
    public:
};

#endif