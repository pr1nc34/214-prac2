#ifndef BICYCLE_H
#define BICYCLE_H

#include "TravelMode.h"

class Bicycle : public TravelMode {
public:
    explicit Bicycle(Traveller* owner);
    ~Bicycle() override;
    
    void move() override;
    TravelMode* getNextMode(const std::string& event) override;
    std::string getName() const override;
};

#endif // BICYCLE_H