#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"
#include <string>
using std::string;

class teacher : public person
{
private:
    unsigned int staffNumber;
    unsigned int officeNumber;
    string position;
    string staffEmail;

public:
    teacher(unsigned int staffNumber, unsigned int officeNumber, string position, string staffEmail, string firstName, string lastName, string dob, string email, unsigned int contactNum, address &address_);
    teacher(unsigned int staffNumber, unsigned int officeNumber, string position, string staffEmail, person &person_);
    unsigned int getStaffNumber();
    unsigned int getOfficeNumber();
    string getPosition();
    string getStaffEmail();
    void setOfficeNumber(unsigned int officeNum);
    void setPosition(string position);
    void setStaffEmail(string email);
};

#endif