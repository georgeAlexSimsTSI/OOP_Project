#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"
#include <string>
using std::string;

/**
 * @brief Derived class from person that adds variables for a professor 
 */
class professor : public person
{
private:
    unsigned int staffNumber;
    unsigned int officeNumber;
    string position;
    string staffEmail;

public:
    professor(unsigned int staffNumber, unsigned int officeNumber, string position, string staffEmail, person &person_);
    unsigned int getStaffNumber();
    unsigned int getOfficeNumber();
    string getPosition();
    string getStaffEmail();
    void setOfficeNumber(unsigned int officeNum);
    void setPosition(string position);
    void setStaffEmail(string email);
};

#endif