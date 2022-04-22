#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"
#include <string>
using std::string;

/**
 * @brief Derived class from Person that adds variables for a Professor
 */
class Professor : public Person
{
private:
    unsigned int staffNumber;
    unsigned int officeNumber;
    string position;
    string staffEmail;

public:
    Professor();
    Professor(unsigned int staffNumber, unsigned int officeNumber, string position, string staffEmail, Person &person);
    unsigned int getStaffNumber();
    unsigned int getOfficeNumber();
    string getPosition();
    string getStaffEmail();
    void setOfficeNumber(unsigned int officeNum);
    void setPosition(string position);
    void setStaffEmail(string email);
};

#endif