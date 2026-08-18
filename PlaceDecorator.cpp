#include "PlaceDecorator.h"

//PlaceDecorator
PlaceDecorator::PlaceDecorator(Place* p) : wrapped(p){

    if(p == nullptr){

        std::cout << "Invalid Place" << std::endl;
    }
}

void PlaceDecorator::describe(){

    wrapped->describe();
}

std::string PlaceDecorator::getName(){

    return wrapped->getName();
}

PlaceDecorator::~PlaceDecorator(){

    delete wrapped;
}


//WeatherFeature

WeatherFeature::WeatherFeature(Place* p, std::string condition) : PlaceDecorator(p), condition(condition){}

void WeatherFeature::describe(){

    std::cout << "Weather is: " << condition << std::endl;
    PlaceDecorator::describe();
}

//TollFeature

TollFeature::TollFeature(Place* p, double fee) : PlaceDecorator(p), fee(fee){

    if(this->fee < 0){

        std::cout << "Invalid fee, defaulting to 0" << std::endl;
        this->fee = 0;
    }
}

void TollFeature::describe(){

    std::cout << "Toll fee: R" << fee << std::endl;
    PlaceDecorator::describe();
}

//QuestFeature

QuestFeature::QuestFeature(Place* p) : PlaceDecorator(p){}

void QuestFeature::announceQuest(){
    
    std::cout << "There are 4 new quests in this location" << std::endl;
}

void QuestFeature::describe(){

    announceQuest();
    PlaceDecorator::describe();
}

//ShrineFeature

ShrineFeature::ShrineFeature(Place* p) : PlaceDecorator(p){}

void ShrineFeature::shrineEffect(){
    std::cout << "Traveller feels a sense of calm" << std::endl;
}

void ShrineFeature::describe(){

    shrineEffect();
    PlaceDecorator::describe();
}