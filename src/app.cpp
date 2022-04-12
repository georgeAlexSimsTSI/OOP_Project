#include "../include/app.h"

app::app(){
    sys = uniSystem();
}

app::app(uniSystem& sys){
    this->sys = sys; 
}


void app::displayStudents()
{
    vector<student> students = sys.getStudent();
    for (student i : students)
    {
        // student num firstName lastName gpa
        cout << "Student num: " + std::to_string(i.getStudentNumber()) + " " + i.getFullName() + " GPA: " + std::to_string(i.getGPA()) << endl;
    }
}

void app::displayStudent(unsigned int studentNum) // student num firstName lastName gpa
{
    try
    {
        student i = sys.getStudent(studentNum); // throws an error if student isn't found
        cout << "Student num: " + std::to_string(i.getStudentNumber()) + " " + i.getFullName() + " GPA: " + std::to_string(i.getGPA()) << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No student with that ID was found" << endl;
    }
}

void app::displayProfessors()
{
    vector<professor> professors = sys.getProfessor();
    for (professor i : professors)
    {
        // staff num firstName lastName position email
        cout << i.getStaffNumber() << " " << i.getFullName() << " " << i.getPosition() << " " << i.getStaffEmail() << endl;
    }
}

void app::displayProfessor(unsigned int staffNum) // staff num firstName lastName position
{
    try
    {
        professor i = sys.getProfessor(staffNum); // throws an error if student isn't found
        cout << i.getStaffNumber() << " " << i.getFullName() << " " << i.getPosition() << " " << i.getStaffEmail() << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No professor with that ID was found" << endl;
    }
}

void app::displayYears() // year numberOfStudents numberOfActiveModules
{
    vector<year> years = sys.getYear();
    for (year i : years)
    {
        cout << i.getYear() << " Students:" << i.getStudents().size() << " Professors: " << i.getProfessors().size() << " Active Modules" << i.getActiveModules().size() << endl;
    }
}

void app::displayYear(unsigned int yearVal) // year numberOfStudents numberOfActiveModules
{
    try
    {
        year i = sys.getYear(yearVal); // throws an error if student isn't found
        cout << i.getYear() << " Students:" << i.getStudents().size() << " Professors: " << i.getProfessors().size() << " Active Modules: " << i.getActiveModules().size() << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No Year found" << endl;
    }
}

void app::displayModuleInstances() // {code = year+modulecode}year moduleCode display assignment
{
    // displays instances from the currently selected year
    vector<moduleInstance> moduleInstances = currentYear->getActiveModules();
    for (auto i : moduleInstances)
    { // year moduleCode display assignment
        cout << i.getYear() << " " << i.getModule().getModuleCode() << " Assignments: " << i.getAssignments().size() << endl;
    }
}

void app::displayModuleInstance(string code)
{
    try
    {
        moduleInstance i = currentYear->getActiveModule(code);
        cout << i.getYear() << " " << i.getModule().getModuleCode() << " Assignments: " << i.getAssignments().size() << endl;
    }
    catch (std::domain_error e)
    {
        cout << "No Year found" << endl;
    }
}

void app::displayAssignments() // code + desc
{
    vector<assignment> assignments = this->currentModuleInstance->getAssignments();
    for(auto i : assignments){
        cout << "Code: " << i.getCode() << " description: " << i.getDesc() << endl;
    }
}