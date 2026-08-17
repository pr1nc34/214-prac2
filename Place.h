#ifndef PLACE_H
#define PLACE_H


#include <vector>
#include <string>
#include <iostream>

class Place{

    public:
    virtual void describe() = 0;
    virtual std::string getName() = 0;
    virtual void add(Place * pl);
    virtual ~Place();

};




#endif