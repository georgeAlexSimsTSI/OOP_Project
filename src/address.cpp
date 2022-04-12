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