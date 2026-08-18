#include "Place.h"
#include "Location.h"
#include "Region.h"
#include "PlaceDecorator.h"
#include "BiomeFactory.h"
#include <vector>

int main(){

    //Composite: a small nested world, some places already decorated
    Region* world = new Region("World");

    Region* savanna = new Region("Savanna");
    savanna->add(new WeatherFeature(new Location("Watering Hole"), "Dry"));
    savanna->add(new Location("Dry Plains"));
    world->add(savanna);

    Region* reef = new Region("Reef");
    reef->add(new TollFeature(new Location("Pearl Cove"), 3.5));
    reef->add(new QuestFeature(new Location("Sunken Wreck")));
    world->add(reef);

    world->add(new ShrineFeature(new Location("Old Shrine")));
    world->add(nullptr);

    std::cout << "=== Full map ===" << std::endl;
    world->describe();

    std::cout << "\n=== Savanna's immediate contents ===" << std::endl;
    savanna->describeChildren();

    //Decorator: same three features, two different stacking orders, no new classes
    std::cout << "\n=== Decorator stacking, order A ===" << std::endl;
    Place* stackA = new QuestFeature(new TollFeature(new WeatherFeature(new Location("Border Post"), "Windy"), 2.0));
    stackA->describe();

    std::cout << "\n=== Decorator stacking, order B ===" << std::endl;
    Place* stackB = new WeatherFeature(new QuestFeature(new TollFeature(new Location("Mountain Pass"), 4.0)), "Snowing");
    stackB->describe();

    std::cout << "\n=== Decorator built on a null place (validation only) ===" << std::endl;
    Place* badDeco = new TollFeature(nullptr, -5.0);
    delete badDeco;

    //Abstract Factory: every biome family, spawned and used
    std::cout << "\n=== Biomes ===" << std::endl;
    std::vector<BiomeFactory*> biomes;
    biomes.push_back(new DesertFactory());
    biomes.push_back(new OceanFactory());
    biomes.push_back(new ForestFactory());
    biomes.push_back(new CityFactory());

    for(auto& biome : biomes){
        Terrain* terrain = biome->createTerrain();
        NPC* npc = biome->createNPC();
        Obstacle* obstacle = biome->createObstacle();

        terrain->describe();
        npc->describe();
        npc->interact();
        obstacle->describe();
        obstacle->resolve();
        std::cout << std::endl;

        delete terrain;
        delete npc;
        delete obstacle;
    }

    //Cleanup
    delete world;
    delete stackA;
    delete stackB;
    for(auto& biome : biomes) delete biome;

    return 0;
}