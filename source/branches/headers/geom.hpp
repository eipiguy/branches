class Point;
class CVector;

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

    Point& operator+=( const CVector &rhs );
    friend Point operator+( Point lhs, const CVector &rhs );

    double distance( const Point &other );

    void print();
};

class CVector {
    public:
    union {
        double components[3] = { 0, 0, 1 };
        struct { double dx, dy, dz; };
    };

    CVector(){}
    CVector( double componentsIn[3] );
    CVector( double dxIn, double dyIn, double dzIn );

    double& operator[]( size_t i );
    const double& operator[]( size_t i ) const;

    CVector& operator+=( const CVector &rhs );
    CVector& operator-=( const CVector &rhs );
    friend CVector operator+( CVector lhs, const CVector &rhs );
    friend CVector operator-( CVector lhs, const CVector &rhs );

    friend CVector operator-( Point lhs, const Point &rhs );

    CVector& operator*=( const double &rhs );
    friend CVector operator*( double lhs, const CVector &rhs );
    friend CVector operator*( CVector lhs, const double &rhs );

    // Dot Product
    friend double operator*( CVector lhs, const CVector &rhs );

    CVector cross( const CVector &rhs ) const;

    void normalize();
    void rotate( const double angle, const CVector &normalAxis );

    double length() const;

    void print() const;
};