#include "Traveller.h"
#include "TravelMode.h"
#include <iostream>

Traveller::Traveller(TravelMode* startMode)
    : mode(startMode), nearBicycle(false), nearCar(false),
      licensed(false), atWaterLocation(false), atShore(false) {
    if (!mode) std::cerr << "Warning: Traveller constructed without a starting TravelMode.\n";
}

Traveller::~Traveller() { delete mode; }

void Traveller::move() { 
    if (mode) mode->move(); 
}

bool Traveller::requestTransition(const std::string& event) {
    if (!mode) return false;

    TravelMode* next = mode->getNextMode(event);
    if (!next) {
        std::cout << "Cannot " << event << " from " << mode->getName() << ".\n";
        return false;
    }

    delete mode;
    mode = next;
    std::cout << "You are now travelling by " << mode->getName() << ".\n";
    return true;
}

std::string Traveller::getCurrentModeName() const {
    return mode ? mode->getName() : "None";
}

bool Traveller::isNearBicycle() const     { return nearBicycle; }
bool Traveller::isNearCar() const         { return nearCar; }
bool Traveller::hasLicense() const        { return licensed; }
bool Traveller::isAtWaterLocation() const { return atWaterLocation; }
bool Traveller::isAtShore() const         { return atShore; }

void Traveller::setNearBicycle(bool value)     { nearBicycle = value; }
void Traveller::setNearCar(bool value)         { nearCar = value; }
void Traveller::setHasLicense(bool value)      { licensed = value; }
void Traveller::setAtWaterLocation(bool value) { atWaterLocation = value; }
void Traveller::setAtShore(bool value)         { atShore = value; }