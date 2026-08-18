#include "BiomeFactory.h"

BiomeFactory::~BiomeFactory(){}

//Desert
Terrain* DesertFactory::createTerrain(){

    return new DesertTerrain();
}

NPC* DesertFactory::createNPC(){

    return new DesertNPC();
}

Obstacle* DesertFactory::createObstacle(){

    return new DesertObstacle();
}

//Ocean
Terrain* OceanFactory::createTerrain(){

    return new OceanTerrain();
}

NPC* OceanFactory::createNPC(){

    return new OceanNPC();
}

Obstacle* OceanFactory::createObstacle(){

    return new OceanObstacle();
}

//Forest
Terrain* ForestFactory::createTerrain(){

    return new ForestTerrain();
}

NPC* ForestFactory::createNPC(){

    return new ForestNPC();
}

Obstacle* ForestFactory::createObstacle(){

    return new ForestObstacle();
}

//City
Terrain* CityFactory::createTerrain(){

    return new CityTerrain();
}

NPC* CityFactory::createNPC(){

    return new CityNPC();
}

Obstacle* CityFactory::createObstacle(){
    
    return new CityObstacle();
}