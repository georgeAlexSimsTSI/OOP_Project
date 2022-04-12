#include "../include/student.h"
#include "../include/professor.h"
#include "../include/assignment.h"
#include "../include/module.h"
#include "../include/moduleInstance.h"
#include "../include/year.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using std::string;
using std::vector;

int main(){

    address a = address();
    person p = person("Jane","Smith","09/07/2020","fakeEmail@email.com","01793434757", a);

    student s = student(934563u, 1u, 2016u, p);
    professor prof = professor(01u, 001u, "TA", "businesEmail@email.com", p);
    
    a.update("SA2OPJ","16", "Dryden", "Swansea", "Absinths"); //doesn't change p or s 

    module_ mod = module_("CS43","Test module");
    vector<assignment> assignments = vector<assignment>();
    assignment assignmentTest = assignment("Assignment 1","test functionality");
    assignments.push_back(assignmentTest);
    assignment assignmentTest2 = assignment("Assignment 2","test functionality");
    assignments.push_back(assignmentTest2);
    moduleInstance ins = moduleInstance(prof,assignments, 0u, mod);
    moduleInstance* insPointer = &ins;

    s.addModule(insPointer);
    auto sMods = s.getModules();

    ins.giveGrade(s.getStudentNumber(),"Assignment 1", 55.0f);
    ins.giveGrade(s.getStudentNumber(),"Assignment 2", 88.0f);
    std::cout << ins.getStudentAverage(934563u) << std::endl;
    
    vector<module_> modules {mod};
    vector<student*> students {&s};
    vector<professor*> professors {&prof};
    vector<moduleInstance> activeModules {ins};
    year year_ = year(2022u,modules,students, professors, activeModules);
    
    return 0;
}