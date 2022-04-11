// #ifndef MODULEINSTANCE_H
// #define MODULEINSTANCE_H

// #include "student.h"
// #include "professor.h"
// #include "assignment.h"
// #include "module.h"
// #include <string>
// #include <vector>
// #include <stdexcept>

// using std::domain_error;
// using std::string;
// using std::vector;

// class moduleInstance
// {
// private:
//     professor professor_;
//     vector<student> students;
//     vector<assignment> assignments;
//     unsigned int year;
//     module_ module__;

// public:
//     moduleInstance();
//     moduleInstance(moduleInstance &moduleInstance_);
//     moduleInstance(professor &professor_, vector<student> students, vector<assignment> assignments, unsigned int year, module_ module__);
//     professor &getProfessor();
//     void setProfessor(professor &professor_);
//     vector<student> &getStudents();
//     void setStudents(vector<student> &students);
//     unsigned int getYear();
//     student &getStudent(unsigned int studentNum) throw();
//     vector<assignment> &getAssignments();
//     void setAssignment(vector<assignment> &assignments);
//     void addAssignment(assignment &assignment_);
//     void addAssignment(string code, string desc);
//     module_ &getModule();
//     float getStudentAverage(unsigned int studentNum);
// };

// #endif