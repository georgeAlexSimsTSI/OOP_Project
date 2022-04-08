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
    address address_;
    string firstName;
    string lastName;
    unsigned int contactNumber;

public:
    person();
    person(string firstName, string lastName, string dob, string email, unsigned int contactNum, address &address_);
    person(person &person_);
    string getFirstName() const;
    string getLastName() const;
    string getFullName() const;
    string getEmail() const;
    unsigned int getContactNum() const;
    address &getAddress();
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setEmail(const string &email);
    void setContactNum(const unsigned int contactNum);
    void updateAddress(const address &address_);
    string getString(); // string representing the address
    // std::ostream &operator<<(std::ostream &stream, person &person_);
};

#endif