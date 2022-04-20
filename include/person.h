#ifndef PERSON_H
#define PERSON_H

#include "address.h"
#include <string>
using std::string;

/**
 * @brief Data storage class representing a person that will be expanded for student and teachers
 */
class person
{
private:
protected:
    string dob; // research date datatypes later, not that important for this project
    string email;
    string firstName;
    string lastName;
    string contactNumber;
    address address_; // making this a reference causes a lot of pain in the derived classes

public:
    person();
    person(string firstName, string lastName, string dob, string email, string contactNum, address address_);
    string getFirstName() const;
    string getLastName() const;
    string getFullName() const;
    string getEmail() const;
    string getContactNum() const;
    string getDateOfBirth() const;
    address &getAddress();
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setEmail(const string &email);
    void setDateOfBirth(const string &dob);
    void setContactNum(const string contactNum);
    void setAddress(const address &address_);
};

#endif