#ifndef BIOMEPRODUCT_H
#define BIOMEPRODUCT_H


class Terrain{

    public:
    virtual void describe() const = 0;
    virtual ~Terrain();


};


class NPC{

    public:
    virtual void describe() const = 0;
    virtual void interact() const = 0;
    virtual ~NPC();

};

class Obstacle{

    public:
    virtual void describe() const = 0;
    virtual void resolve() const = 0;
    virtual ~Obstacle();
};


class DessertTerrain : public Terrain{

    public:
    DessertTerrain();
};
class DessertNPC : public NPC{
    
    public:
    DessertNPC();

};
class DessertObstacle : public Obstacle{

    public:
    DessertObstacle();
};


class OceanTerrain : public Terrain{

    public:
    OceanTerrain();
};
class OceanNPC : public NPC{
    
    public:
    OceanNPC();

};
class OceanObstacle : public Obstacle{

    public:
    OceanObstacle();
};


class ForrestTerrain : public Terrain{

    public:
    ForrestTerrain();
};
class ForrestNPC : public NPC{
    
    public:
    ForrestNPC();

};
class ForrestObstacle : public Obstacle{

    public:
    ForrestObstacle();
};



class CityTerrain : public Terrain{

    public:
    CityTerrain();
};
class CityNPC : public NPC{
    
    public:
    CityNPC();

};
class CityObstacle : public Obstacle{

    public:
    CityObstacle();
};

#endif