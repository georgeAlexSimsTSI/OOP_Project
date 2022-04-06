#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "student.h"
#include "teacher.h"
#include "assignment.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class classRoom
{
private:
    teacher teacher_;
    vector<student> students;
    vector<assignment> assignments;
    string subject; // may change to an enum
    unsigned int roomNum;

public:
    classRoom(teacher &teacher_, string subject, unsigned int roomNum);
    classRoom(classRoom &classRoom_);
};

#endif