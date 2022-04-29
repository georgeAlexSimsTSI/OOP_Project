#include "../include/Person.h"

Person::Person()
{
    this->firstName = "N/A";
    this->lastName = "N/A";
    this->dob = "N/A";
    this->email = "N/A";
    this->contactNumber = "00000000000";
    this->address = Address();
}

Person::Person(const string & firstName, const string & lastName, const string & dob, const string & email, const string & contactNum, const Address & address) : address(address)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->dob = dob;
    this->email = email;
    this->contactNumber = contactNum;
}

string Person::getFirstName() const
{
    return this->firstName;
}

string Person::getLastName() const
{
    return this->lastName;
}

string Person::getFullName() const
{
    return this->firstName + " " + this->lastName;
}

string Person::getEmail() const
{
    return this->email;
}

string Person::getContactNum() const
{
    return this->contactNumber;
}

string Person::getDateOfBirth() const
{
    return this->dob;
}

Address &Person::getAddress()
{
    return this->address;
}

void Person::setFirstName(const string &firstName)
{
    this->firstName = firstName;
}

void Person::setLastName(const string &lastName)
{
    this->lastName = lastName;
}

void Person::setEmail(const string &email)
{
    this->email = email;
}

void Person::setContactNum(const string &contactNum)
{
    this->contactNumber = contactNum;
}

void Person::setAddress(const Address &address)
{
    this->address = address;
}

void Person::setDateOfBirth(const string &dob)
{
    this->dob = dob;
}
