#ifndef BIOMEFACTORY_H
#define BIOMEFACTORY_H

#include "BiomeProduct.h"

class BiomeFactory
{

public:
    virtual Terrain* createTerrain() const = 0 ;
    virtual NPC* createNPC() const = 0;
    virtual Obstacle* createObstacle() const = 0;
};


class Desert : public BiomeFactory{

    public:
    Terrain* createTerrain() const override;
    NPC* createNPC() const override;
    Obstacle* createObstacle() const override;
};
class Ocean  : public BiomeFactory{

    public:
    Terrain* createTerrain() const override;
    NPC* createNPC() const override;
    Obstacle* createObstacle() const override;
};
class Forrest  : public BiomeFactory{

    public:
    Terrain* createTerrain() const override;
    NPC* createNPC() const override;
    Obstacle* createObstacle() const override;
};
class City  : public BiomeFactory{

    public:
    Terrain* createTerrain() const override;
    NPC* createNPC() const override;
    Obstacle* createObstacle() const override;
};



#endif