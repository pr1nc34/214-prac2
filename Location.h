#ifndef LOCATION_H
#define LOCATION_H

#include "Place.h"

class Location : public Place{

    private:
    std::string name;

    public:
    Location(std::string name);
    void describe() override;
    std::string getName() override;
    ~Location();

};

#endif