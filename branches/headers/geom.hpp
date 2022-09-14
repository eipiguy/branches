class Point;
class Direction;

class Point {
    public:
    union {
        double coordinates[3] = { 0 };
        double x, y, z;
    };

    Point(){}
    Point( double coordinatesIn[3] );
    Point( double xIn, double yIn, double zIn );

    double& operator[]( size_t i );
    const double& operator[]( size_t i ) const;

    Point& operator+=( const Direction &rhs );
    friend Point operator+( Point lhs, const Direction &rhs );

    void print();
};

class Direction {
    public:
    union {
        double components[3] = { 0 };
        double dx, dy, dz;
    };

    Direction(){}

    double& operator[]( size_t i );
    const double& operator[]( size_t i ) const;

    Direction& operator+=( const Direction &rhs );
    friend Direction operator+( Direction lhs, const Direction &rhs );

    Direction& operator*=( const double &rhs );
    friend Direction operator*( double lhs, const Direction &rhs );
    friend Direction operator*( Direction lhs, const double &rhs );

    friend double operator*( Direction lhs, const Direction &rhs );

    void print();
};