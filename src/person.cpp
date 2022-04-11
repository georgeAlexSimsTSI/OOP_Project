#include "../include/person.h"


person::person()
{
    this->firstName = "N/A";
    this->lastName = "N/A";
    this->dob = "N/A";
    this->email = "N/A";
    this->contactNumber = "00000000000";
    this->address_ = address();
}

person::person(string firstName, string lastName, string dob, string email, string contactNum, address address_) : address_(address_)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->dob = dob;
    this->email = email;
    this->contactNumber = contactNum;
}

string person::getFirstName() const
{
    return this->firstName;
}

string person::getLastName() const
{
    return this->lastName;
}

string person::getFullName() const
{
    return this->firstName + this->lastName;
}

string person::getEmail() const
{
    return this->email;
}

string person::getContactNum() const
{
    return this->contactNumber;
}

address &person::getAddress()
{
    return this->address_;
}

void person::setFirstName(const string &firstName)
{
    this->firstName = firstName;
}

void person::setLastName(const string &lastName)
{
    this->lastName = lastName;
}

void person::setEmail(const string &email)
{
    this->email = email;
}

void person::setContactNum(const string contactNum)
{
    this->contactNumber = contactNum;
}

void person::updateAddress(const address &address_)
{
    this->address_ = address_;
}