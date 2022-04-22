#include "../include/Address.h"

Address::Address()
{
    this->postCode = "N/A";
    this->houseNumber = "N/A"; // maybe something like 15a or 15b to indicate flat number
    this->roadName = "N/A";
    this->town = "N/A";
    this->county = "N/A";
}

Address::Address(string postCode, string houseNumber, string roadName, string town, string county)
{
    this->postCode = postCode;
    this->houseNumber = houseNumber; // maybe something like 15a or 15b to indicate flat number
    this->roadName = roadName;
    this->town = town;
    this->county = county;
}

void Address::update(string postCode, string houseNumber, string roadName, string town, string county)
{
    this->postCode = postCode;
    this->houseNumber = houseNumber; // maybe something like 15a or 15b to indicate flat number
    this->roadName = roadName;
    this->town = town;
    this->county = county;
}

string Address::getPostCode() const { return postCode; }
string Address::getHouseNumber() const { return houseNumber; }
string Address::getRoadName() const { return roadName; }
string Address::getTown() const { return town; }
string Address::getCounty() const { return county; }