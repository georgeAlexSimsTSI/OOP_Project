#include "../include/professor.h"

professor::professor() : person(){
    this->staffNumber = 0u;
    this->officeNumber = 0u;
    this->position = "Teaching professor";
    this->staffEmail = "";
}

professor::professor(unsigned int staffNumber, unsigned int officeNumber, string position, string staffEmail, string firstName, string lastName, string dob, string email, unsigned int contactNum, address &address_) : person(firstName, lastName, dob, email, contactNum, address_)
{
    this->staffNumber = staffNumber;
    this->officeNumber = officeNumber;
    this->position = position;
    this->staffEmail = staffEmail;
}
professor::professor(unsigned int staffNumber, unsigned int officeNumber, string position, string staffEmail, person &person_) : person(person_)
{
    this->staffNumber = staffNumber;
    this->officeNumber = officeNumber;
    this->position = position;
    this->staffEmail = staffEmail;
}

unsigned int professor::getStaffNumber()
{
    return this->staffNumber;
}

unsigned int professor::getOfficeNumber()
{
    return this->officeNumber;
}

string professor::getPosition()
{
    return this->position;
}

string professor::getStaffEmail()
{
    return this->staffEmail;
}

void professor::setOfficeNumber(unsigned int officeNum)
{
    this->officeNumber = officeNum;
}

void professor::setPosition(string position)
{
    this->position = position;
}

void professor::setStaffEmail(string email)
{
    this->staffEmail = email;
}