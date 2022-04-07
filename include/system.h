#ifndef SYSTEM_H
#define SYSTEM_H

#include "student.h"
#include "professor.h"
#include "year.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class uniSystem{
    private:
        vector<year> years;
        vector<student> students;
        vector<professor> professors;
    public:
};

#endif