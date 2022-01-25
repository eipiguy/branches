#include <stdexcept>

//===========================================================================//

struct Point;

///////////////////////////////////////////////////////////////////////////////

struct Point {
    double x, y, z;

    double operator[](int i);
    Point operator=(Point& copyFrom);
    bool operator==(Point& compareAgainst);
    Point operator+(Point& addTo);
    Point operator-();
    Point operator-(Point& subtractFrom);
    Point operator%(Point& dotWith);
    Point operator*(double scalarMultiple);
    Point operator*(Point& crossWith);
};