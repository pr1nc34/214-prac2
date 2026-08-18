#ifndef PLACEDECORATOR_H
#define PLACEDECORATOR_H

#include "Place.h"

class PlaceDecorator : public Place
{
    private:
    Place* wrapped;

    public:
    PlaceDecorator(Place* p);
    void describe() override;
    std::string getName() override;
    ~PlaceDecorator();
};


class WeatherFeature : public PlaceDecorator{

    private:
    std::string condition;

    public:
    WeatherFeature(Place* p, std::string condition);
    void describe() override;
};

class TollFeature : public PlaceDecorator{

    private:
    double fee;

    public:
    TollFeature(Place* p, double fee);
    void describe() override;
};

class QuestFeature : public PlaceDecorator{

    public:
    QuestFeature(Place* p);
    void announceQuest();
    void describe() override;
};

class ShrineFeature : public PlaceDecorator{

    public:
    ShrineFeature(Place* p);
    void shrineEffect();
    void describe() override;
};


#endif