#ifndef BOAT_H
#define BOAT_H

#include "TravelMode.h"

class Boat : public TravelMode {
public:
    explicit Boat(Traveller* owner);
    ~Boat() override;
    
    void move() override;
    TravelMode* getNextMode(const std::string& event) override;
    std::string getName() const override;
};

#endif // BOAT_H