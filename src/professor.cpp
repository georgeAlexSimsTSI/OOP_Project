#include "../include/Professor.h"

Professor::Professor() : Person()
{
    this->staffNumber = 0u;
    this->officeNumber = 0u;
    this->position = "TA";
    this->staffEmail = "N/A";
}

Professor::Professor(const unsigned int &staffNumber, const unsigned int &officeNumber, const string &position, const string &staffEmail, Person &person) : Person(person)
{
    this->staffNumber = staffNumber;
    this->officeNumber = officeNumber;
    this->position = position;
    this->staffEmail = staffEmail;
}

unsigned int Professor::getStaffNumber() const
{
    return this->staffNumber;
}

unsigned int Professor::getOfficeNumber() const
{
    return this->officeNumber;
}

string Professor::getPosition() const
{
    return this->position;
}

string Professor::getStaffEmail() const
{
    return this->staffEmail;
}

void Professor::setOfficeNumber(unsigned int officeNum)
{
    this->officeNumber = officeNum;
}

void Professor::setPosition(const string &position)
{
    this->position = position;
}

void Professor::setStaffEmail(const string &email)
{
    this->staffEmail = email;
}