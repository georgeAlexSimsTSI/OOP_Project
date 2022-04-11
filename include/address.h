#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using std::string;

/**
 * @brief Data storage class that represents a persons home address
 */
class address
{
private:
    string postCode;
    string houseNumber; // maybe something like 15a or 15b to indicate flat number
    string roadName;
    string town;
    string county;

public:
    address();
    address(string postCode, string houseNumber, string roadName, string town, string county);
    address(address &address_); // copy constructor
    ~address();                 // shouldn't require anything here as address shouldn't be creating anything on the heap
    string getString();         // string representing the address
    // std::ostream &operator<<(std::ostream os, const address &obj);

    void update(string postCode, string houseNumber, string roadName, string town, string county);
};

#endif