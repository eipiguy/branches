#include <vector>
//#include <stdexcept>

//===========================================================================//

#define MIN_LENGTH 0
#define MIN_DIAM 1

//---------------------------------------------------------------------------//

struct Point;
class Node;
class Branch;

///////////////////////////////////////////////////////////////////////////////

struct Point {
    double x, y, z;
    double operator[](int i);
    Point operator=(Point& copyFrom);
    bool operator==(Point& compareAgainst);
    Point operator+(Point& addTo);
    Point operator-();
    Point operator-(Point& subtractFrom);
};

//===========================================================================//

class Node {
    private:
    double distanceAlongParent = 0;
    double angleFromParentPlane = 0;
    Branch* parent = nullptr;
    Point location = { 0, 0, 0 };

    Node(Branch &inputParent);

    public:
    Node();

    Branch* getParentPtr();
    double getDistanceAlongParent();
    double getAngleFromParentPlane();
};

//---------------------------------------------------------------------------//

class Branch : public Node {
    private:
    double diam = MIN_DIAM;
    double length = MIN_LENGTH;
    std::vector<Branch*> children;

    Branch(Node& baseNode);

    public:    
    double getDiam();
    double getLength();

    int numChildren();
    Node* operator[](int index);
};