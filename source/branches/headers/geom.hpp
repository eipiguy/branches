class Point;
class Direction;

class Point {
    public:
    union {
        double coordinates[3] = { 0 };
        struct { double x, y, z; };
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
        double components[3] = { 0, 0, 1 };
        struct { double dx, dy, dz; };
    };

    Direction(){}
    Direction( double componentsIn[3] );
    Direction( double dxIn, double dyIn, double dzIn );

    double& operator[]( size_t i );
    const double& operator[]( size_t i ) const;

    Direction& operator+=( const Direction &rhs );
    friend Direction operator+( Direction lhs, const Direction &rhs );

    Direction& operator*=( const double &rhs );
    friend Direction operator*( double lhs, const Direction &rhs );
    friend Direction operator*( Direction lhs, const double &rhs );

    // Dot Product
    friend double operator*( Direction lhs, const Direction &rhs );

    friend Direction cross( const Direction &lhs, const Direction &rhs );

    void rotate( const double angle, Direction &normalAxis );

    double length();

    void print();
};