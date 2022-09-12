#include <vector>

class Branch;

using std::size_t;
typedef std::vector<Branch*> vBranch;

class Branch {
    protected:
    Branch* parent = nullptr;
    vBranch children = { nullptr };
    double
        length = 0,
        diameter = 0;

    Branch();
    Branch( Branch &inputParent );

    public:
    Branch* getParent();
    Branch* operator[]( size_t i );

    double getLength();
    double getDiameter();
};