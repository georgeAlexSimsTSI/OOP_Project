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

    /**
     * @brief responsible for adding new students, module or moduleinstances to a year
     */
    void modifyYear();

    /**
     * @brief Take inputs required to add a new year
     */
    void addYear();

    /**
     * @brief responsible for modifying a students details e.g. change name or address
     */
    void modifyStudent();

    /**
     * @brief  Take inputs required to create a new student
     */
    void addStudent();

    /**
     * @brief responsible for modifying a professor
     */
    void modifyProfessor();

    /**
     * @brief Take inputs required to create a new professor
     */
    void addProfessor();

    /**
     * @brief method to modify a person e.g. student or professor
     */
    void modifyPerson(person *currentPerson);

    /**
     * @brief Take inputs required to make a new person
     * @return person instance to create a derived class e.g. student or professor
     */
    person addPerson();

    /**
     * @brief Take inputs to create a module, used to create a module instance
     */
    module_ addModule();

    /**
     * @brief modify a module instance e.g. giving student grades
     */
    void modifyModuleInstance();

    /**
     * @brief take inputs to create a new module instance
     */
    void addModuleInstance();

    /**
     * @brief method to modify an assignmet
     */
    void modifyAssignment(); // e.g. giving grades

    /**
     * @brief take inputs to create an assignment for the currently selected module
     */
    void addAssignment();

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

    //methods to select objects from the the system, should list options then take user input
    void selectYear();
    void selectStudent();
    void selectProfessor();
    void selectModuleInstance(); //This should always run after select year
    void selectAssignment(); //should run after select moduleInstance

    void run();
};

#endif