#ifndef APP_H
#define APP_H

#include "system.h"
#include "userInput.h"

#include <iostream>
using std::cout;
using std::endl;

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
class app{
    private:
        uniSystem sys;
        year * currentYear;
        module_ * currentModule;
        moduleInstance * currentModuleInstance;
        student * currentStudent;
        professor * currentProfessor;

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
    void modifyPerson(person * currentPerson);

    /**
     * @brief Take inputs required to make a new person 
     * @return person instance to create a derived class e.g. student or professor
     */
    person addPerson();

    /**
     * @brief modify module variables, this only effects future instances 
     */
    void modifyModule();

    /**
     * @brief Take inputs to create a module
     */
    void addModule();

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
     * @brief utility functions to print out details of the years and students
     */
    void displayStudents();
    void displayStudent(unsigned int studentNum); // student num firstName lastName gpa
    void displayProfessors();
    void displayProfessor(unsigned int staffNum); // staff num firstName lastName position
    void displayYears();
    void displayYear(unsigned int year);// year numberOfStudents numberOfActiveModules
    void displayModuleInstance(string code); // {code = year+modulecode}year moduleCode display assignment
    void displayAssignment(string code); //code + desc 


    void run();
};

#endif