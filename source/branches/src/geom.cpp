#include <iostream>
#include <math.h>

#include "geom.hpp"

using std::size_t;
using std::cout;
using std::endl;

///////////////////////////////////////////////////////////////////////////////

Point :: Point( double coordinatesIn[3] ) {
    for( size_t i=0; i<3; ++i ) {
        coordinates[i] = coordinatesIn[i];
    }
}

Point :: Point( double xIn, double yIn, double zIn ) {
    x = xIn;
    y = yIn;
    z = zIn;
}

double& Point :: operator[]( size_t i ) {
    return coordinates[i];
}

const double& Point :: operator[]( size_t i ) const {
    return coordinates[i];
}

Point& Point :: operator+=( const CVector &rhs ) {
    for( size_t i=0; i<3; ++i ) {
        (*this)[i] += rhs[i];
    }
    return *this;
}

Point operator+( Point lhs, const CVector &rhs ) {
    lhs += rhs;
    return lhs;
}

double Point :: distance( const Point &other ) {
    return (other - *this).length();
}

void Point :: print() {
    cout << "(x,y,z) = ( " << x << ", " << y << ", " << z << " )" << endl; 
}

///////////////////////////////////////////////////////////////////////////////

CVector :: CVector( double componentsIn[3] ) {
    for( size_t i=0; i<3; ++i ) {
        components[i] = componentsIn[i];
    }
}

CVector :: CVector( double dxIn, double dyIn, double dzIn ) {
    dx = dxIn;
    dy = dyIn;
    dz = dzIn;
}

double& CVector :: operator[]( size_t i ) {
    return components[i];
}

const double& CVector :: operator[]( size_t i ) const {
    return components[i];
}

CVector& CVector :: operator+=( const CVector &rhs ) {
    for( size_t i=0; i<3; ++i ) {
        (*this)[i] += rhs[i];
    }
    return *this;
}

CVector& CVector :: operator-=( const CVector &rhs ) {
    for( size_t i=0; i<3; ++i ) {
        (*this)[i] -= rhs[i];
    }
    return *this;
}

CVector operator+( CVector lhs, const CVector &rhs ) {
    lhs += rhs;
    return lhs;
}

CVector operator-( CVector lhs, const CVector &rhs ) {
    lhs -= rhs;
    return lhs;
}

CVector operator-( Point lhs, const Point &rhs ) {
    CVector delta;
    for( size_t i=0; i<3; ++i ) {
        delta[i] = lhs[i] - rhs[i];
    }
    return delta;
}

CVector& CVector :: operator*=( const double &rhs ) {
    for( size_t i=0; i<3; ++i ) {
        (*this)[i] *= rhs;
    }
    return *this;
}

CVector operator*( double lhs, const CVector &rhs ) {
    CVector vec = rhs;
    vec *= lhs;
    return vec;
}

CVector operator*( CVector lhs, const double &rhs ) {
    lhs *= rhs;
    return lhs;
}

double operator*( CVector lhs, const CVector &rhs ) {
    return lhs.dx*rhs.dx + lhs.dy*rhs.dy + lhs.dz*rhs.dz;
}

CVector CVector :: cross( const CVector &rhs ) const {
    return CVector( dy*rhs.dz - dz*rhs.dy, dz*rhs.dx - dx*rhs.dz, dx*rhs.dy - dy*rhs.dx );
}

void CVector :: rotate( const double angle, const CVector &normalAxis ) {
    CVector unitAxis = ( 1 / normalAxis.length() ) * normalAxis;
    CVector normal = unitAxis.cross( *this );
    double cosAngle = cos(angle);
    double sinAngle = sin(angle);

    *this = ( unitAxis * (*this) )*unitAxis + cosAngle*normal.cross( unitAxis ) + sinAngle*normal;
}

void CVector :: normalize() {
    double l = length();
    if( l != 0 )
        (*this) *= 1 / l;
}

double CVector :: length() const { return sqrt((*this) * (*this)); }

void CVector :: print() const {
    cout << "(dx,dy,dz) = ( " << dx << ", " << dy << ", " << dz << " )" << endl; 
}