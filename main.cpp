#include "Place.h"
#include "Location.h"
#include "Region.h"
#include "PlaceDecorator.h"
#include "BiomeFactory.h"
#include "Traveller.h"
#include "OnFoot.h"
#include <new>
#include <vector>
#include <iostream>

static void runTravellerSmokeTest() {
    std::cout << "\n=== Traveller state machine ===\n";
    void* storage = ::operator new(sizeof(Traveller));
    Traveller* traveller = nullptr;

    try {
        traveller = new (storage) Traveller(new OnFoot(reinterpret_cast<Traveller*>(storage)));
        
        std::cout << "Starting mode: " << traveller->getCurrentModeName() << "\n";
        traveller->move();

        std::cout << "\n-- Invalid transition attempts --\n";
        traveller->requestTransition("mount");
        traveller->requestTransition("board");

        std::cout << "\n-- Bicycle path --\n";
        traveller->setNearBicycle(true);
        traveller->requestTransition("mount");
        std::cout << "Current mode: " << traveller->getCurrentModeName() << "\n";
        traveller->move();
        traveller->requestTransition("mount");

        std::cout << "\n-- Car path --\n";
        traveller->setHasLicense(true);
        traveller->setNearCar(true);
        traveller->requestTransition("mount");
        std::cout << "Current mode: " << traveller->getCurrentModeName() << "\n";
        traveller->move();
        traveller->requestTransition("dismount");
        std::cout << "Current mode: " << traveller->getCurrentModeName() << "\n";
        traveller->move();

        std::cout << "\n-- Boat path --\n";
        traveller->requestTransition("dismount");
        traveller->setNearBicycle(false);
        traveller->setAtWaterLocation(true);
        traveller->requestTransition("board");
        std::cout << "Current mode: " << traveller->getCurrentModeName() << "\n";
        traveller->move();
        traveller->requestTransition("disembark");

        std::cout << "\n-- Shore disembark validation --\n";
        traveller->requestTransition("board");
        traveller->setAtShore(true);
        traveller->requestTransition("disembark");
        std::cout << "Current mode: " << traveller->getCurrentModeName() << "\n";
        traveller->move();

        std::cout << "\n-- Unknown event check --\n";
        traveller->requestTransition("fly");
    } catch (...) {
        if (traveller) traveller->~Traveller();
        ::operator delete(storage);
        throw;
    }

    traveller->~Traveller();
    ::operator delete(storage);
}

int main() {
    // Composite: a small nested world, some places already decorated
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

    std::cout << "=== Full map ===\n";
    world->describe();

    std::cout << "\n=== Savanna's immediate contents ===\n";
    savanna->describeChildren();

    // Decorator: same three features, two different stacking orders, no new classes
    std::cout << "\n=== Decorator stacking, order A ===\n";
    Place* stackA = new QuestFeature(new TollFeature(new WeatherFeature(new Location("Border Post"), "Windy"), 2.0));
    stackA->describe();

    std::cout << "\n=== Decorator stacking, order B ===\n";
    Place* stackB = new WeatherFeature(new QuestFeature(new TollFeature(new Location("Mountain Pass"), 4.0)), "Snowing");
    stackB->describe();

    std::cout << "\n=== Decorator built on a null place (validation only) ===\n";
    Place* badDeco = new TollFeature(nullptr, -5.0);
    delete badDeco;

    // Abstract Factory: every biome family, spawned and used
    std::cout << "\n=== Biomes ===\n";
    std::vector<BiomeFactory*> biomes = {
        new DesertFactory(), new OceanFactory(),
        new ForestFactory(), new CityFactory()
    };

    for(auto& biome : biomes) {
        Terrain* terrain = biome->createTerrain();
        NPC* npc = biome->createNPC();
        Obstacle* obstacle = biome->createObstacle();

        terrain->describe();
        npc->describe();
        npc->interact();
        obstacle->describe();
        obstacle->resolve();
        std::cout << "\n";

        delete terrain;
        delete npc;
        delete obstacle;
    }

    // Cleanup
    delete world;
    delete stackA;
    delete stackB;
    for(auto& biome : biomes) delete biome;

    runTravellerSmokeTest();

    return 0;
}