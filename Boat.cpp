#include "Boat.h"
#include "Traveller.h"
#include "OnFoot.h"
#include <iostream>

Boat::Boat(Traveller* owner) : TravelMode(owner) {}
Boat::~Boat() {}

void Boat::move() { std::cout << "You row steadily across the water.\n"; }
std::string Boat::getName() const { return "Boat"; }

TravelMode* Boat::getNextMode(const std::string& event) {
    if (event == "disembark" && traveller->isAtShore()) return new OnFoot(traveller);
    return nullptr;
}