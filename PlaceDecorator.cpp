#include "PlaceDecorator.h"


//PlaceDecorator
PlaceDecorator::PlaceDecorator(Place* p){

    if(p != nullptr){

        wrapped = p;
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

WeatherFeature::WeatherFeature(Place* p, std::string condition) : PlaceDecorator(p){

    if(p != nullptr){
        condition = condition;
    }

}

void WeatherFeature::describe(){

    std::cout << "Weather is: " <<condition << std::endl;

    PlaceDecorator::describe();

}

//TollFeature

TollFeature::TollFeature(Place* p, double fee) : PlaceDecorator(p){

    if(p != nullptr && fee >= 0){
        fee = fee;
    }

}

void TollFeature::describe(){

    std::cout << "Toll fee: R" << fee << std::endl;

    PlaceDecorator::describe();

}

//QuestFeature

QuestFeature::QuestFeature(Place* p) : PlaceDecorator(p){


}

void QuestFeatureannounceQuest(){

    std::cout << "There are 4 new quests in this location" << std::endl;
}

void QuestFeature::describe(){

    announceQuest();
    PlaceDecorator::describe();
}

//ShrineFeature

ShrineFeature::ShrineFeature(Place* p) : PlaceDecorator(p){


}

void ShrineFeature::shrineEffect(){

    std::cout << "Traveller feels a sense of calm" << std::endl;

}

void ShrineFeature::describe(){

    shrineEffect();
    PlaceDecorator::describe();
}
