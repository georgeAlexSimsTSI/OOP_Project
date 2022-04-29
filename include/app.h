#ifndef APP_H
#define APP_H

#include "system.h"
#include "userInput.h"

#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

/**
 * @brief the main application that handles user interaction and inputs
 *
 * modify or add flow: *
 * Student -> Person -> Address
 * Professor -> Person -> Address
 * Year -> module
 * Year -> ModuleInstance
 * Year -> ModuleInstance -> Assignment
 */
class App
{
private:
    UniSystem sys;
    Year *currentYear;
    ModuleInstance *currentModuleInstance;
    Assignment *currentAssignment;
    Student *currentStudent;
    Professor *currentProfessor;

    // methods to take in inputs and create new objects
    void addYear();           // Year, students, professors
    void addStudent();        // Student number, YearOfStudy, enrollmentYear, Person
    void addProfessor();      // staff number, office number, position, staffemail
    void addModuleInstance(); // Professor, Year, module
    void addAssignment();     // code, description
    static Person addPerson();       // first name, last name, dob, email, contact number, Address(postcode, house number, road name, town, county)
    static Module addModule();       // module code, description

    /**
     * @brief utility functions to print out details of the years and students
     */
    void displayStudent();
    void displayStudent(unsigned int studentNum); // Student num firstName lastName gpa
    void displayProfessor();
    void displayProfessor(unsigned int staffNum); // staff num firstName lastName position email
    void displayYear();
    void displayYear(unsigned int YearVal);  // Year numberOfStudents numberOfActiveModules
    void displayModuleInstance();            // of current Year
    void displayModuleInstance(const string &code); // {code = Year+modulecode}Year moduleCode display Assignment
    void displayAssignment();                // of current module //code + desc
    void displayAssignment(const string &code);     // Assignment code

    // methods to select objects from the the system, should list options then take user input
    void selectYear();           // no restriction on selection
    void selectStudent();        // select from entire system not specific Year
    void selectProfessor();      // select from entire system not specific Year
    void selectModuleInstance(); // This should always run after select Year
    void selectAssignment();     // should run after select ModuleInstance

    vector<Professor *> addAllprofessors(); // creates a vector of all professors in the system
    vector<Professor *> selectprofessors(); // build a vector of Professor pointers by specifying staff numbers

    vector<Student *> addAllstudents(); // creates a vector of all students from the entire system
    vector<Student *> selectstudents(); // build a vector of Student pointers by specifying Student numbers

    // methods to update the current object
    void updateYear();             // add Student, Professor from wider system, add module instance, update module instance
    void updatePerson(Person *p);  // update Personal details and Address
    Address setAddress(Address a); // update Address details
    void updateStudent();          // update Person then Student details
    void updateProfessor();        // update Person then Professor details
    void updateModuleInstance();   // update module, update Assignment or change Professor
    void updateModule();           // update module description, not allowing change to module code
    void updateAssignment();       // update description or give grade
    void displayObjectProcess();
    void addObjectProcess();
    void updateObjectProcess();
    void deleteObjectProcess();

public:
    App();
    App(const UniSystem &sys);
    void run();
};

#endif