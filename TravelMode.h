#ifndef TRAVELMODE_H
#define TRAVELMODE_H

#include <string>

class Traveller;

class TravelMode {
public:
    explicit TravelMode(Traveller* owner);
    virtual ~TravelMode();

    virtual void move() = 0;
    virtual TravelMode* getNextMode(const std::string& event) = 0;
    virtual std::string getName() const = 0;

    TravelMode(const TravelMode&) = delete;
    TravelMode& operator=(const TravelMode&) = delete;

protected:
    Traveller* traveller;
};

#endif // TRAVELMODE_H