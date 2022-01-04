#include <vector>

#define MIN_LENGTH 1
#define MIN_DIAM 1

class Branches{
    private:
    // Personal Parameters
    double diam;
    double length;
    Branches* parent;

    // Attached Children = 
        // <child*,
        // distance from start (mm), 
        // radians counterclockwise from parent 0 angle>
    std::vector<Branches*> children;
    std::vector<double> child_distances;
    std::vector<double> child_angles;

    public:
    Branches();
    Branches(double first_diam, double first_length);
    void AppendChild(double distance_from_last, double angle_from_parent);
    void AppendChild(double distance_from_last, double angle_from_parent, double first_diam, double first_length);
};