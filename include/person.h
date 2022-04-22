#ifndef PERSON_H
#define PERSON_H

#include "address.h"
#include <string>
using std::string;

/**
 * @brief Data storage class representing a Person that will be expanded for Student and teachers
 */
class Person
{
private:
protected:
    string firstName;
    string lastName;
    string dob; // research date datatypes later, not that important for this project
    string email;
    string contactNumber;
    Address address; // making this a reference causes a lot of pain in the derived classes
public:
    Person();
    Person(string firstName, string lastName, string dob, string email, string contactNum, Address address);
    string getFirstName() const;
    string getLastName() const;
    string getFullName() const;
    string getEmail() const;
    string getContactNum() const;
    string getDateOfBirth() const;
    Address &getAddress();
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setEmail(const string &email);
    void setDateOfBirth(const string &dob);
    void setContactNum(const string contactNum);
    void setAddress(const Address &address);
};

#endif