#include "../include/student.h"
#include "../include/professor.h"
#include "../include/assignment.h"
#include "../include/module.h"
#include "../include/moduleInstance.h"
#include "../include/year.h"
#include "../include/system.h"
#include "../include/app.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using std::string;
using std::vector;

int main()
{

    address a = address();
    person p = person("Jane", "Smith", "09/07/2020", "fakeEmail@email.com", "01793434757", a);

    student s = student(934563u, 1u, 2016u, p);
    professor prof = professor(01u, 001u, "TA", "businesEmail@email.com", p);

    a.update("SA2OPJ", "16", "Dryden", "Swansea", "Absinths"); // doesn't change p or s

    module_ mod = module_("CS43", "Test module");
    moduleInstance ins = moduleInstance(prof, {}, 0u, mod);
    year year_ = year(2022u, {mod}, {&s}, {&prof}, {ins});

    uniSystem sys = uniSystem({s}, {prof}, {year_});
    year *year_2022 = & sys.getYear(2022u); 
    moduleInstance *year_2022_module_CS43 = & year_2022->getActiveModule("CS43");
    year_2022_module_CS43->addAssignment("Assignment 1", "test functionality");
    year_2022_module_CS43->addAssignment("Assignment 2", "test functionality");
    year_2022_module_CS43->giveGrade(934563u,"Assignment 1",55.0f);
    year_2022_module_CS43->giveGrade(934563u,"Assignment 2",88.0f);

    student *student934563 = &sys.getStudent(934563u);
    student934563->addModule(&sys.getYear(2022u).getActiveModule("CS43"));
    student934563 = &sys.getStudent(934563u);
    auto student934563Modules = student934563->getModules();

    app application = app(sys);
    application.displayStudents();
    application.displayProfessors();
    application.displayYears();
    application.currentYear = &application.sys.getYear(2022u);
    application.displayModuleInstance("CS43");    
    application.currentModuleInstance = &application.sys.getYear(2022u).getActiveModule("CS43");
    application.displayAssignments();

    application.addStudent();
    application.addProfessor();    
    application.displayStudents();
    application.displayProfessors();



    return 0;
}