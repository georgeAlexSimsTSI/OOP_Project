#include "../include/address.h"

address::address(string postCode, string houseNumber, string roadName, string town, string county){
    this->postCode = postCode;
    this->houseNumber = houseNumber; // maybe something like 15a or 15b to indicate flat number
    this->roadName = roadName;
    this->town = town;
    this->county = county;
}

//copy constructor
address::address(address &address_){
    this->postCode = address_.postCode;
    this->houseNumber = address_.houseNumber; // maybe something like 15a or 15b to indicate flat number
    this->roadName = address_.roadName;
    this->town = address_.town;
    this->county = address_.county;
}

// address::address(address &&address_){
//     this->postCode = address_.postCode;
//     this->houseNumber = address_.houseNumber; // maybe something like 15a or 15b to indicate flat number
//     this->roadName = address_.roadName;
//     this->town = address_.town;
//     this->county = address_.county;
// }