#include "../include/address.h"

address::address()
{
    this->postCode = "N/A";
    this->houseNumber = "N/A"; // maybe something like 15a or 15b to indicate flat number
    this->roadName = "N/A";
    this->town = "N/A";
    this->county = "N/A";
}

address::address(string postCode, string houseNumber, string roadName, string town, string county)
{
    this->postCode = postCode;
    this->houseNumber = houseNumber; // maybe something like 15a or 15b to indicate flat number
    this->roadName = roadName;
    this->town = town;
    this->county = county;
}

void address::update(string postCode, string houseNumber, string roadName, string town, string county)
{
    this->postCode = postCode;
    this->houseNumber = houseNumber; // maybe something like 15a or 15b to indicate flat number
    this->roadName = roadName;
    this->town = town;
    this->county = county;
}

string address::getPostCode() const { return postCode; }
string address::getHouseNumber() const { return houseNumber; }
string address::getRoadName() const { return roadName; }
string address::getTown() const { return town; }
string address::getCounty() const { return county; }