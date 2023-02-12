#include <array>
#include <vector>
#include <memory>

#include "geom.hpp"

class Branch;
class Leaf;

#define MIN_DIAM 0.2
#define LEAVES_PER_BRANCH 1

using std::size_t;
typedef std::vector<std::unique_ptr<Branch>> vBranch;
typedef std::array<Leaf, LEAVES_PER_BRANCH> aLeaf;

class Leaf {
    CVector meridian;
    double occlusion = 1;
    double moisture;

    public:
    Point base;

    Leaf(){}
    Leaf( const Point &baseIn, const CVector &lengthIn, const double occlusionIn = 1 );

    Point getEnd();
    void print();
};

class Branch {
    class LineSeg {
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

        void print();
    };

    protected:
    double diameter = MIN_DIAM;
    LineSeg profile;
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
    CVector getTipToTail();

    double measureRadAngle( Branch &comparison );
    double measureRadAngleBetweenChildren( const size_t i, const size_t j );
    double measureMinRadAngleToChildren( Branch &comparison );
    double distance( Branch &compare );

    void rotate( double angle, CVector &normalAxis );

    void print();
};

#undef MIN_DIAM
#undef LEAVES_PER_BRANCH