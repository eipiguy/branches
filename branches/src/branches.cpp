#include "branches.hpp"

///////////////////////////////////////////////////////////////////////////////

Branch :: Branch() {}

Branch :: Branch( Branch &inputParent ) 
    : parent(&inputParent) {}

Branch* Branch :: getParent() { return parent; }
Branch* Branch :: operator[]( size_t i ) { return children[i]; }

double Branch :: getLength() { return length; }
double Branch :: getDiameter() { return diameter; }