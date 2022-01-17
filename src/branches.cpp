#include "branches.hpp"

///////////////////////////////////////////////////////////////////////////////

double Point :: operator[](int i){

    switch(i){
        
        case 0:
            return x;
        break;
        
        case 1:
            return y;
        break;

        case 2:
            return z;
        break;

        default:
            throw std::out_of_range( "Point only has x, y, and z values" );
    }

    // should not get here
    throw std::runtime_error( "should not be outside operator[] switch statement" );
}

Point Point :: operator=(Point& copyFrom){
    Point copy = { copyFrom.x, copyFrom.y, copyFrom.z };
    return copy;
}

bool Point :: operator==(Point& compareAgainst){
    return (x == compareAgainst.x) 
        && (y == compareAgainst.y)
        && (z == compareAgainst.z);
}

Point Point :: operator+(Point& addTo){
    Point sum = { 0, 0, 0 };
    sum.x = x + addTo.x;
    sum.y = y + addTo.y;
    sum.z = z + addTo.z;
    return sum;
}

Point Point :: operator-(){
    Point inverse = { -x, -y, -z };
    return inverse;
}

Point Point :: operator-(Point& subtractFrom){
    Point difference = { 0, 0, 0 };
    difference.x = x - subtractFrom.x;
    difference.y = y - subtractFrom.y;
    difference.z = z - subtractFrom.z;
    return difference;
}

///////////////////////////////////////////////////////////////////////////////

Node :: Node() {}

Node :: Node(Branch &inputParent) 
    : parent(&inputParent) {}

Branch* Node :: getParentPtr() { return parent; }
double Node :: getDistanceAlongParent() { return distanceAlongParent; }
double Node :: getAngleFromParentPlane() { return angleFromParentPlane; }

///////////////////////////////////////////////////////////////////////////////

Branch :: Branch(Node &baseNode){}

///////////////////////////////////////////////////////////////////////////////

double Branch :: getDiam() { return diam; }
double Branch :: getLength() { return length; }

int Branch :: numChildren(){ return children.size(); }
Node* Branch :: operator[](int index) {
    return ( 0 <= index && index < children.size() ) ?
        children[index] : nullptr;
}