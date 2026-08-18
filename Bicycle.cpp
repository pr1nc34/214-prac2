#include "Bicycle.h"
#include "Traveller.h"
#include "OnFoot.h"
#include "Car.h"
#include <iostream>

Bicycle::Bicycle(Traveller* owner) : TravelMode(owner) {}
Bicycle::~Bicycle() {}

void Bicycle::move() { std::cout << "You pedal briskly down the road.\n"; }
std::string Bicycle::getName() const { return "Bicycle"; }

TravelMode* Bicycle::getNextMode(const std::string& event) {
    if (event == "dismount") return new OnFoot(traveller);
    if (event == "mount" && traveller->hasLicense() && traveller->isNearCar()) return new Car(traveller);
    return nullptr;
}