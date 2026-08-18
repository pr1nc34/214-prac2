#ifndef TRAVELLER_H
#define TRAVELLER_H

#include <string>

class TravelMode;

class Traveller {
public:
    explicit Traveller(TravelMode* startMode);
    ~Traveller();

    Traveller(const Traveller&) = delete;
    Traveller& operator=(const Traveller&) = delete;

    void move();
    bool requestTransition(const std::string& event);
    std::string getCurrentModeName() const;

    bool isNearBicycle() const;
    bool isNearCar() const;
    bool hasLicense() const;
    bool isAtWaterLocation() const;
    bool isAtShore() const;

    void setNearBicycle(bool value);
    void setNearCar(bool value);
    void setHasLicense(bool value);
    void setAtWaterLocation(bool value);
    void setAtShore(bool value);

private:
    TravelMode* mode;
    bool nearBicycle;
    bool nearCar;
    bool licensed;
    bool atWaterLocation;
    bool atShore;
};

#endif // TRAVELLER_H