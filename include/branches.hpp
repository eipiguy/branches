#include <vector>

#define MIN_LENGTH 0
#define MIN_DIAM 1

class Branch {
    private:
    double diam = MIN_DIAM;
    double length = MIN_LENGTH;

    double distFromParent = 0;
    double angleFromParent = 0;

    Branch* parent = nullptr;
    std::vector<Branch*> children;

    Branch(Branch* first_parent);
    Branch(
        Branch* first_parent,
        double first_diam,
        double first_length);

    public:
    Branch();
    Branch(
        double first_diam,
        double first_length);
    
    double getDiam();
    double getLength();

    Branch* getParentPtr();
    Branch* operator[](int index);
    int size();
    Branch* getLastChild();

    double getDistFromParent();
    double getAngleFromParent();

    void appendChild();
    void appendChild(
        double distFromParent,
        double anglefromParent);
};