#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using std::string;

/**
 * @brief Data storage class that represents a Persons home Address
 */
class Address
{
private:
    string postCode;
    string houseNumber; // maybe something like 15a or 15b to indicate flat number
    string roadName;
    string town;
    string county;

public:
    Address();
    Address(const string &postCode, const string &houseNumber, const string &roadName, const string &town, const string &county);
    void update(const string &postCode, const string &houseNumber, const string &roadName, const string &town, const string &county);
    string getPostCode() const;
    string getHouseNumber() const;
    string getRoadName() const;
    string getTown() const;
    string getCounty() const;
};

#endif