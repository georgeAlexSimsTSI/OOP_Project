#include "../include/Professor.h"

Professor::Professor() : Person()
{
    this->staffNumber = 0u;
    this->officeNumber = 0u;
    this->position = "TA";
    this->staffEmail = "N/A";
}

Professor::Professor(unsigned int staffNumber, unsigned int officeNumber, string position, string staffEmail, Person &person) : Person(person)
{
    this->staffNumber = staffNumber;
    this->officeNumber = officeNumber;
    this->position = position;
    this->staffEmail = staffEmail;
}

unsigned int Professor::getStaffNumber()
{
    return this->staffNumber;
}

unsigned int Professor::getOfficeNumber()
{
    return this->officeNumber;
}

string Professor::getPosition()
{
    return this->position;
}

string Professor::getStaffEmail()
{
    return this->staffEmail;
}

void Professor::setOfficeNumber(unsigned int officeNum)
{
    this->officeNumber = officeNum;
}

void Professor::setPosition(string position)
{
    this->position = position;
}

void Professor::setStaffEmail(string email)
{
    this->staffEmail = email;
}