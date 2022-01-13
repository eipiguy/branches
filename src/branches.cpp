#include "branches.hpp"

Branch :: Branch(
    Branch* first_parent)
    :   diam(MIN_DIAM),
        length(MIN_LENGTH),
        parent(first_parent) {}

Branch :: Branch(
    Branch* first_parent,
    double first_diam,
    double first_length)
    :   diam(first_diam >= MIN_DIAM ? first_diam : MIN_DIAM),
        length(first_length >= MIN_LENGTH ? first_length : MIN_LENGTH),
        parent(first_parent) {}

Branch :: Branch()
    :   diam(MIN_DIAM),
        length(MIN_LENGTH) {}

Branch :: Branch(
    double first_diam,
    double first_length)
    :   diam(first_diam >= MIN_DIAM ? first_diam : MIN_DIAM),
        length(first_length >= MIN_LENGTH ? first_length : MIN_LENGTH) {}

double Branch :: getDiam() { return diam; }
double Branch :: getLength() { return length; }
Branch* Branch :: getParentPtr() { return parent; }
Branch* Branch :: operator[](int index) {
    return ( 0 <= index && index < children.size() ) ? children[index] : nullptr;
}
Branch* Branch :: getLastChild() { return children[children.size()-1]; }

double Branch :: getDistFromParent() { return distFromParent; }
double Branch :: getAngleFromParent() { return angleFromParent; }

void Branch :: appendChild() {
    children.push_back(new Branch(this, length, 0));
}
void Branch :: appendChild(
    double distFromParentIn,
    double anglefromParentIn)
{
    children.push_back(new Branch(this));
    children.back()->distFromParent = distFromParentIn;
    children.back()->angleFromParent = anglefromParentIn;
}