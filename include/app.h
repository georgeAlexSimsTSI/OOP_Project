#ifndef APP_H
#define APP_H

#include "system.h"
#include "userInput.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

/**
 * @brief the main application that handles user interaction and inputs
 *
 * modify or add flow: *
 * student -> person -> address
 * professor -> person -> address
 * year -> module
 * year -> moduleInstance
 * year -> moduleInstance -> assignment
 */
class app
{
public: // private: //public for testing
    uniSystem sys;
    year *currentYear;
    moduleInstance *currentModuleInstance;
    assignment *currentAssignment;
    student *currentStudent;
    professor *currentProfessor;

public:
    app();
    app(uniSystem &sys);

    // methods to take in inputs and create new objects
    void addYear();           // year, students, professors
    void addStudent();        // student number, yearOfStudy, enrollmentYear, Person
    void addProfessor();      // staff number, office number, position, staffemail
    void addModuleInstance(); // professor, year, module
    void addAssignment();     // code, description
    person addPerson();       // first name, last name, dob, email, contact number, address(postcode, house number, road name, town, county)
    module_ addModule();      // module code, description

    /**
     * @brief utility functions to print out details of the years and students
     */
    void displayStudents();
    void displayStudent(unsigned int studentNum); // student num firstName lastName gpa
    void displayProfessors();
    void displayProfessor(unsigned int staffNum); // staff num firstName lastName position email
    void displayYears();
    void displayYear(unsigned int yearVal);  // year numberOfStudents numberOfActiveModules
    void displayModuleInstances();           // of current year
    void displayModuleInstance(string code); // {code = year+modulecode}year moduleCode display assignment
    void displayAssignments();               // of current module //code + desc

    // methods to select objects from the the system, should list options then take user input
    void selectYear();           // no restriction on selection
    void selectStudent();        // select from entire system not specifc year
    void selectProfessor();      // select from entire system not specifc year
    void selectModuleInstance(); // This should always run after select year
    void selectAssignment();     // should run after select moduleInstance

    vector<professor *> addAllProfessors(); // creates a vector of all professors in the system
    vector<professor *> selectProfessors(); // build a vector of professor pointers by specifying staff numbers

    vector<student *> addAllStudents(); // creates a vector of all students from the entire system
    vector<student *> selectStudents(); // build a vector of student pointers by specifying student numbers

    // methods to update the current object
    void updateYear();                // add student, professor from wider system, add module instance, update module instance
    void updatePerson(person *p);     // update personal details and address
    address updateAddress(address a); // update address details
    void updateStudent();             // update person then student details
    void updateProfessor();           // update person then professor details
    void updateModuleInstance();      // update module, update assignment or change professor
    void updateModule();              // update module description, not allowing change to module code
    void updateAssignment();          // update description or give grade

    void run();

    void displayObjectProcess();
    void getObjectProcess();
    void addObjectProcess();
    void updateObjectProcess();
    void deleteObjectProcess();
};

#endif