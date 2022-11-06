#include <array>
#include <vector>
#include <memory>

#include "geom.hpp"

class Branch;
class Leaf;

#define MIN_DIAM 0.2
#define MIN_LENGTH 0.1
#define LEAVES_PER_BRANCH 1

using std::size_t;
typedef std::vector<std::unique_ptr<Branch>> vBranch;
typedef std::array<Leaf, LEAVES_PER_BRANCH> aLeaf;

class Leaf {
    double occlusion = 1;
    Direction meridian;

    public:
    Point base;

    Leaf(){}
    Leaf( Point &baseIn, Direction &lengthIn, double occlusionIn = 1 );

    Point getEnd();
    void print();
};

class Branch {
    class CurveProfile {
        public:
        Point base;
        Direction length;

        CurveProfile(){}
        CurveProfile( Point &baseIn, Direction &lengthIn );

        double pathLength();
        Point getPoint( const double &param );
        Point getEnd();

        double measureRadAngle( CurveProfile &comparison );

        void print();
    };

    protected:
    double diameter = MIN_DIAM;
    CurveProfile profile;
    aLeaf leaves = {};
    vBranch children = {};

    void resetChildBasePoints();
    void addLeaf( std::unique_ptr<Leaf> &leaf );

    public:
    Branch();
    void addChild();
    void addChild( std::unique_ptr<Branch> &child );

    size_t getNumChildren();
    size_t getNumLeaves();
    double getDiameter();
    Direction getTipToTail();

    double measureRadAngle( Branch &comparison );
    double measureRadAngle( size_t i, size_t j );

    void print();
};