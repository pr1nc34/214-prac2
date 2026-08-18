#include "Car.h"
#include "Traveller.h"
#include "Bicycle.h"
#include <iostream>

Car::Car(Traveller* owner) : TravelMode(owner) {}
Car::~Car() {}

void Car::move() { std::cout << "You drive off down the highway.\n"; }
std::string Car::getName() const { return "Car"; }

TravelMode* Car::getNextMode(const std::string& event) {
    if (event == "dismount") return new Bicycle(traveller);
    return nullptr;
}