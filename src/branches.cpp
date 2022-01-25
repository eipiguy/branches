#include "branches.hpp"

///////////////////////////////////////////////////////////////////////////////

Node :: Node() {}

Node :: Node(double x, double y)
    : root({x,y,0}) {}

Node :: Node(Branch &inputParent) 
    : parent(&inputParent) {}

//===========================================================================//

Branch* Node :: getParentPtr() { return parent; }

///////////////////////////////////////////////////////////////////////////////

Branch :: Branch(Node &baseNode){}

//===========================================================================//

double Branch :: getLength() { return length; }
double Branch :: getDiam() { return diam; }

int Branch :: numChildren(){ return children.size(); }
Node* Branch :: operator[](int index) {
    return ( 0 <= index && index < children.size() ) ?
        children[index] : nullptr;
}