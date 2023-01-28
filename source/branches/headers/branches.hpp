#include <array>
#include <vector>
#include <memory>

#include "geom.hpp"

class Branch;
class Leaf;

#define MIN_DIAM 0.2
#define MIN_LENGTH 0.1
#define DEFLECTION_RAD 0.17453292519943295769236907684886
#define LEAVES_PER_BRANCH 1

using std::size_t;
typedef std::vector<std::unique_ptr<Branch>> vBranch;
typedef std::array<Leaf, LEAVES_PER_BRANCH> aLeaf;

class Leaf {
    double occlusion = 1;
    Direction meridian;
    double moisture;

    public:
    Point base;

    Leaf(){}
    Leaf( const Point &baseIn, const Direction &lengthIn, const double occlusionIn = 1 );

    Point getEnd();
    void print();
};

class Branch {
    class CurveProfile {
        public:
        Point base;
        Direction path;

        CurveProfile(){}
        CurveProfile( const Point &baseIn, const Direction &lengthIn );

        double length();
        Point getPoint( const double &param );
        Point getEnd();

        double measureRadAngle( const CurveProfile &comparison );
        double minDistance( CurveProfile &compare );

        void rotateAroundBase( const double angle, Direction &normalAxis );

        void print();
    };

    protected:
    double diameter = MIN_DIAM;
    CurveProfile profile;
    aLeaf leaves = {};
    vBranch children = {};

    void adjustNewChild( std::unique_ptr<Branch> &child );
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
    double measureRadAngle( const size_t i, const size_t j );
    double measureMinRadAngle( Branch &comparison );
    double minDistance( Branch &compare );

    void rotate( const double angle, Direction &normalAxis );

    void print();
};