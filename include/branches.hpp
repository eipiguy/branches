#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
//#include <stdexcept>
#include "geometry.hpp"

//===========================================================================//

#define MIN_LENGTH 0
#define MIN_DIAM 1

//---------------------------------------------------------------------------//

class Node;
class Branch;

///////////////////////////////////////////////////////////////////////////////

class Node {
    private:
    Branch* parent = nullptr;
    Point root = { 0, 0, 0 };

    Node(Branch &inputParent);

    public:
    Node();
    Node(double x, double y);

    Branch* getParentPtr();
    double getDistanceAlongParent();
    double getAngleFromParentPlane();
};

//===========================================================================//

class Branch : public Node {
    private:
    Point direction = { 0, 0, 1 };
    double length = 0;
    double diam = 0;
    std::vector<Branch*> children;

    Branch(Node& baseNode);

    public:    
    double getDiam();
    double getLength();

    int numChildren();
    Node* operator[](int index);
};