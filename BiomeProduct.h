#ifndef BIOMEPRODUCT_H
#define BIOMEPRODUCT_H

class Terrain{

    public:
    virtual void describe() = 0;
    virtual ~Terrain();
};

class NPC{

    public:
    virtual void describe() = 0;
    virtual void interact() = 0;
    virtual ~NPC();
};

class Obstacle{

    public:
    virtual void describe() = 0;
    virtual void resolve() = 0;
    virtual ~Obstacle();
};


class DesertTerrain : public Terrain{
    public:
    DesertTerrain();
    void describe() override;
};

class DesertNPC : public NPC{
    public:
    DesertNPC();
    void describe() override;
    void interact() override;
};

class DesertObstacle : public Obstacle{
    public:
    DesertObstacle();
    void describe() override;
    void resolve() override;
};


class OceanTerrain : public Terrain{
    public:
    OceanTerrain();
    void describe() override;
};

class OceanNPC : public NPC{
    public:
    OceanNPC();
    void describe() override;
    void interact() override;
};

class OceanObstacle : public Obstacle{
    public:
    OceanObstacle();
    void describe() override;
    void resolve() override;
};


class ForestTerrain : public Terrain{
    public:
    ForestTerrain();
    void describe() override;
};

class ForestNPC : public NPC{
    public:
    ForestNPC();
    void describe() override;
    void interact() override;
};

class ForestObstacle : public Obstacle{
    public:
    ForestObstacle();
    void describe() override;
    void resolve() override;
};


class CityTerrain : public Terrain{
    public:
    CityTerrain();
    void describe() override;
};

class CityNPC : public NPC{
    public:
    CityNPC();
    void describe() override;
    void interact() override;
};

class CityObstacle : public Obstacle{
    public:
    CityObstacle();
    void describe() override;
    void resolve() override;
};

#endif