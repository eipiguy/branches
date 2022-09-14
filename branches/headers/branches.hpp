#include <vector>
#include <memory>

#include "geom.hpp"

class Branch;
class Leaf;

using std::size_t;
typedef std::vector<std::unique_ptr<Branch>> vBranch;
typedef std::vector<std::unique_ptr<Leaf>> vLeaf;

class Branch {
    class CurveProfile {
        protected:
        Point base;
        Direction length;

        public:
        CurveProfile(){}
        CurveProfile( Point baseIn, Direction lengthIn );

        double pathLength();
        Point getPoint( const double &param );
        Point getEnd();

        void print();
    };

    protected:
    double diameter = 0;
    CurveProfile profile = {};
    vBranch children = {};
    vLeaf leaves = {};

    public:
    Branch(){}
    void addChild( std::unique_ptr<Branch> &child );

    size_t getNumChildren();
    double getDiameter();

    void print();
};

class Leaf {};