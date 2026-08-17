#include "Region.h"


void Region::add(Place* p){

    if(p == nullptr){

        std::cout << "Invalid Place" << std::endl;
        return;
    }

    children.push_back(p);

}

Region::~Region(){

    for(auto& a : children){
        delete a;
    }
}