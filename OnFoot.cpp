#include "OnFoot.h"
#include "Traveller.h"
#include "Bicycle.h"
#include "Boat.h"
#include <iostream>

OnFoot::OnFoot(Traveller* owner) : TravelMode(owner) {}
OnFoot::~OnFoot() {}

void OnFoot::move() { std::cout << "You walk along the path.\n"; }
std::string OnFoot::getName() const { return "OnFoot"; }

TravelMode* OnFoot::getNextMode(const std::string& event) {
    if (event == "mount" && traveller->isNearBicycle()) return new Bicycle(traveller);
    if (event == "board" && traveller->isAtWaterLocation()) return new Boat(traveller);
    return nullptr;
}