#include "Place.h"


class Region : public Place{

    private:
    std::string name;
    std::vector<Place*> children;

    public:
    Region(std::string name);
    void add(Place* pl);
    std::vector<Place*>& getChildren();
    void describe() override;
    void describeChildren();
    std::string getName() override;
    ~Region();


};