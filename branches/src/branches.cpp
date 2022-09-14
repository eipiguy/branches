#include <iostream>

#include "branches.hpp"

using std::cout;
using std::endl;

///////////////////////////////////////////////////////////////////////////////

void Branch :: addChild( std::unique_ptr<Branch> &child ) { children.push_back(std::move(child)); }

size_t Branch :: getNumChildren() { return children.size(); }

double Branch :: getDiameter() { return diameter; }

void Branch :: print() {
    cout << endl << "Curve Profile:" << endl;
    profile.print();
    
    cout << endl << " Children (" << getNumChildren() << "):" << endl;
    for( auto &child : children ) {
        child->print();
    }
}

///////////////////////////////////////////////////////////////////////////////

Branch :: CurveProfile :: CurveProfile( Point baseIn, Direction lengthIn )
    : base(baseIn), length(lengthIn) {}

double Branch :: CurveProfile :: pathLength() {
    return sqrt(length*length);
}

Point Branch :: CurveProfile :: getPoint( const double &param ) {
    return base + (param * length);
}

Point Branch :: CurveProfile :: getEnd() {
    return base + length;
}

void Branch :: CurveProfile :: print() {
    cout << "base point: ";
    base.print();

    cout << "length vector: ";
    length.print();

    cout << "path length = " << pathLength() << endl;

    cout << "end point: ";
    getEnd().print();
}