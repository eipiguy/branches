#include <iostream>

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

Point& Point :: operator+=( const Direction &rhs ) {
    for( size_t i=0; i<3; ++i ) {
        (*this)[i] += rhs[i];
    }
    return *this;
}

Point operator+( Point lhs, const Direction &rhs ) {
    lhs += rhs;
    return lhs;
}

void Point :: print() {
    cout << "(x,y,z) = ( " << x << ", " << y << ", " << z << " )" << endl; 
}

///////////////////////////////////////////////////////////////////////////////

Direction :: Direction( double componentsIn[3] ) {
    for( size_t i=0; i<3; ++i ) {
        components[i] = componentsIn[i];
    }
}

Direction :: Direction( double dxIn, double dyIn, double dzIn ) {
    dx = dxIn;
    dy = dyIn;
    dz = dzIn;
}

double& Direction :: operator[]( size_t i ) {
    return components[i];
}

const double& Direction :: operator[]( size_t i ) const {
    return components[i];
}

Direction& Direction :: operator+=( const Direction &rhs ) {
    for( size_t i=0; i<3; ++i ) {
        (*this)[i] += rhs[i];
    }
    return *this;
}

Direction operator+( Direction lhs, const Direction &rhs ) {
    lhs += rhs;
    return lhs;
}

Direction& Direction :: operator*=( const double &rhs ) {
    for( size_t i=0; i<3; ++i ) {
        (*this)[i] *= rhs;
    }
    return *this;
}

Direction operator*( double lhs, const Direction &rhs ) {
    Direction vec = rhs;
    vec *= lhs;
    return vec;
}

Direction operator*( Direction lhs, const double &rhs ) {
    lhs *= rhs;
    return lhs;
}

double operator*( Direction lhs, const Direction &rhs ) {
    return lhs.dx*rhs.dx + lhs.dy*rhs.dy + lhs.dz*rhs.dz;
}

double Direction :: length() { return sqrt((*this) * (*this));}

void Direction :: print() {
    cout << "(dx,dy,dz) = ( " << dx << ", " << dy << ", " << dz << " )" << endl; 

}