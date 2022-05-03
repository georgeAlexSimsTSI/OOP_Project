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
    Professor(const unsigned int &staffNumber, const unsigned int &officeNumber, const string &position, const string &staffEmail, Person &person);
    unsigned int getStaffNumber() const;
    unsigned int getOfficeNumber() const;
    string getPosition() const;
    string getStaffEmail() const;
    void setOfficeNumber(unsigned int officeNum);
    void setPosition(const string &position);
    void setStaffEmail(const string &email);
};

#endif