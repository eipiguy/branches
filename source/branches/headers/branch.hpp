#include <array>
#include <vector>
#include <memory>

#include "geom.hpp"

class Branch;
class Leaf;

#define GROW_ENERGY 1.0
#define MAX_INHIBIT 0.5
#define MIN_DIAM 0.2
#define EXTENSION_DISTANCE 0.2
#define LEAVES_PER_BRANCH 1

using std::size_t;
typedef std::vector<std::unique_ptr<Branch>> vBranch;
typedef std::array<Leaf, LEAVES_PER_BRANCH> aLeaf;

class Nutrients {
    public:
    double moisture;
    double energy;
    double splitInhibit;
};

class Leaf {
    CVector meridian;
    double occlusion = 1;
    double moisture;

    public:
    Point base;

    Leaf(){}
    Leaf( const Point &baseIn, const CVector &lengthIn, const double occlusionIn = 1 );

    Point getEnd() const;
    void print() const;
};

class Branch {
    class LineSeg  {
        public:
        Point base;
        CVector path;

        LineSeg(){}
        LineSeg( const Point &baseIn, const CVector &lengthIn );

        double length() const;
        Point getPoint( double param ) const;
        Point getEnd() const;

        int checkBehindNextToOrInFront( const Point &check ) const;
        bool projIntersect( const LineSeg &compare ) const;
        double measureRadAngle( const LineSeg &comparison ) const;
        double distance( const Point &compare ) const;
        double distance( const LineSeg &compare ) const;

        void rotate( double angle, const CVector &normalAxis );
        void extend( const double distance = EXTENSION_DISTANCE );

        void print() const;
    };

    protected:
    const double maxInhibit = MAX_INHIBIT;
    const double growEnergy = GROW_ENERGY;
    double diameter = MIN_DIAM;
    LineSeg profile;
    aLeaf leaves = {};
    vBranch children = {};
    Nutrients availableNutrients;
    bool isHardened = false;

    void adjustNewChild( std::unique_ptr<Branch> &child );
    void resetBasePoints();
    void addLeaf( std::unique_ptr<Leaf> &leaf );

    public:
    Branch();
    void addChild();
    void addChild( std::unique_ptr<Branch> &child );

    bool canGrow() const;
    bool canSplit() const;

    size_t getNumChildren() const;
    size_t getNumLeaves() const;
    double getDiameter() const;
    CVector getTipToTail() const;

    double measureRadAngle( Branch &comparison ) const;
    double measureRadAngleBetweenChildren( const size_t i, const size_t j ) const;
    double measureMinRadAngleToChildren( Branch &comparison ) const;
    double distance( Branch &compare ) const;

    void rotate( const double angle, const CVector &normalAxis );
    void extend( const double distance = EXTENSION_DISTANCE );
    void grow();

    void print() const;
};

#undef MAX_INHIBIT
#undef MIN_DIAM
#undef EXTENSION_DISTANCE
#undef LEAVES_PER_BRANCH