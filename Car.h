#ifndef CAR_H
#define CAR_H

#include "TravelMode.h"

class Car : public TravelMode {
public:
    explicit Car(Traveller* owner);
    ~Car() override;
    
    void move() override;
    TravelMode* getNextMode(const std::string& event) override;
    std::string getName() const override;
};

#endif // CAR_H