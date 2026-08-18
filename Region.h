#include "Place.h"


class Region : public Place{

    private:
    std::string name;
    std::vector<Place*> children;

    public:
    Region(std::string name);
    void add(Place* pl);
    const std::vector<Place*>& getChildren() const;
    void describe() override;
    void describeChildren();
    std::string getName() override;
    ~Region();


};