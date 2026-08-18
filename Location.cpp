#include "Location.h"

Location::Location(std::string name){

    if(name.empty()){
        std::cout << "Invalid name, defaulting to Unnamed Location" << std::endl;
        this->name = "Unnamed Location";
    } else {
        this->name = name;
    }
}

void Location::describe(){
    std::cout << name << std::endl;
}

std::string Location::getName(){
    return name;
}

Location::~Location(){}