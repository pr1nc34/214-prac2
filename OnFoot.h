#ifndef ONFOOT_H
#define ONFOOT_H

#include "TravelMode.h"

class OnFoot : public TravelMode {
public:
    explicit OnFoot(Traveller* owner);
    ~OnFoot() override;
    
    void move() override;
    TravelMode* getNextMode(const std::string& event) override;
    std::string getName() const override;
};

#endif // ONFOOT_H