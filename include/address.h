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
    void update(string postCode, string houseNumber, string roadName, string town, string county);
    string getPostCode() const;
    string getHouseNumber() const;
    string getRoadName() const;
    string getTown() const;
    string getCounty() const;
};

#endif