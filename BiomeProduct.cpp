#include "BiomeProduct.h"
#include <iostream>

Terrain::~Terrain(){}
NPC::~NPC(){}
Obstacle::~Obstacle(){}


//Desert
DesertTerrain::DesertTerrain(){}

void DesertTerrain::describe(){

    std::cout << "Endless dunes stretch to the horizon, shimmering with heat." << std::endl;
}

DesertNPC::DesertNPC(){}

void DesertNPC::describe(){

    std::cout << "A robed nomad leads a caravan of camels." << std::endl;
}

void DesertNPC::interact(){

    std::cout << "The nomad offers to trade water for supplies." << std::endl;
}

DesertObstacle::DesertObstacle(){}

void DesertObstacle::describe(){

    std::cout << "A sudden sandstorm rolls in, cutting visibility to nothing." << std::endl;
}

void DesertObstacle::resolve(){
    
    std::cout << "You shield your eyes and push through until the storm passes." << std::endl;
}


//Ocean
OceanTerrain::OceanTerrain(){}

void OceanTerrain::describe(){
    std::cout << "Turquoise water laps against a curve of white sand." << std::endl;
}

OceanNPC::OceanNPC(){}

void OceanNPC::describe(){
    std::cout << "A weathered fisherman mends his nets by the shore." << std::endl;
}

void OceanNPC::interact(){
    std::cout << "The fisherman shares a tale of a sunken ship offshore." << std::endl;
}

OceanObstacle::OceanObstacle(){}

void OceanObstacle::describe(){
    std::cout << "A strong riptide pulls at the shallows, blocking the way forward." << std::endl;
}

void OceanObstacle::resolve(){
    std::cout << "You wait for the tide to shift before wading across." << std::endl;
}


//Forest
ForestTerrain::ForestTerrain(){}

void ForestTerrain::describe(){

    std::cout << "Tall pines filter the sunlight into scattered patches of green." << std::endl;
}

ForestNPC::ForestNPC(){}

void ForestNPC::describe(){

    std::cout << "A quiet ranger studies tracks in the underbrush." << std::endl;
}

void ForestNPC::interact(){

    std::cout << "The ranger points out a hidden trail through the trees." << std::endl;
}

ForestObstacle::ForestObstacle(){}

void ForestObstacle::describe(){

    std::cout << "A fallen tree blocks the narrow path ahead." << std::endl;
}
void ForestObstacle::resolve(){

    std::cout << "You climb over the trunk and continue on." << std::endl;
}


//City
CityTerrain::CityTerrain(){}

void CityTerrain::describe(){

    std::cout << "Cobbled streets wind between tall stone buildings." << std::endl;
}

CityNPC::CityNPC(){}

void CityNPC::describe(){

    std::cout << "A street vendor calls out over the noise of the crowd." << std::endl;
}
void CityNPC::interact(){

    std::cout << "The vendor haggles over the price of dried fruit." << std::endl;
}

CityObstacle::CityObstacle(){}

void CityObstacle::describe(){

    std::cout << "A dense crowd fills the square, slowing all movement." << std::endl;
}

void CityObstacle::resolve(){

    std::cout << "You weave carefully through the press of people." << std::endl;
}