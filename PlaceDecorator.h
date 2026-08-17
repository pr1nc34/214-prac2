#ifndef PLACEDECORATOR_H
#define PLACEDECORATOR_H

#include "Place.h"

class PlaceDecorator : public Place
{
protected:
    Place* wrapped;
public:
    PlaceDecorator(Place* p);
    void describe();
    std::string getName();
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

    private:
    std::string quest;

    public:
    QuestFeature(Place* p);
    void announceQuest();
    void describe() override;
};

class ShrineFeature : public PlaceDecorator{

    private:
    std::string name;

    public:
    ShrineFeature(Place* p);
    void shrineEffect();
    void describe() override;
};


#endif