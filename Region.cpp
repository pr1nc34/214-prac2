#include "Region.h"

Region::Region(std::string name){

    if(name.empty()){

        std::cout << "Invalid name, defaulting to Unnamed Region" << std::endl;
        this->name = "Unnamed Region";

    } else {

        this->name = name;
    }
}

void Region::add(Place* p){

    if(p == nullptr){

        std::cout << "Invalid Place" << std::endl;
        return;
    }

    children.push_back(p);
}

const std::vector<Place*>& Region::getChildren() const{

    return children;
}

void Region::describe(){

    std::cout << name << std::endl;

    for(auto& child : children){

        child->describe();
    }
}

void Region::describeChildren(){

    for(auto& child : children){

        std::cout << "- " << child->getName() << std::endl;
    }
}

std::string Region::getName(){

    return name;
}

Region::~Region(){

    for(auto& a : children){
        
        delete a;
    }
}