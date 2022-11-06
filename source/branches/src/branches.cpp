#include <iostream>
#include <math.h>

#include "branches.hpp"

using std::cout;
using std::endl;

///////////////////////////////////////////////////////////////////////////////

Branch :: Branch()
    :   profile(CurveProfile(Point(0,0,0), Direction(0,0,1))) {
    Point endPt = profile.getEnd();
    for(size_t i=0; i<LEAVES_PER_BRANCH; ++i) {
        leaves[i] = Leaf();
    }
}

//=============================================================================

void Branch :: resetChildBasePoints() {
    Point currentEnd = profile.getEnd();

    for( auto &leaf : leaves ) {
        leaf.base = currentEnd;
    }

    for( auto &child : children ) {
        child->profile.base = currentEnd;
        child->resetChildBasePoints();
    }
}

void Branch :: addChild() {
    children.emplace_back(std::make_unique<Branch>());
    resetChildBasePoints();
}

void Branch :: addChild( std::unique_ptr<Branch> &child ) {
    children.emplace_back(std::move(child));
    resetChildBasePoints();
}

Direction Branch :: getTipToTail(){
    return profile.length;
}

double Branch :: measureRadAngle( Branch &comparison ) {
    return acos( ( getTipToTail() * comparison.getTipToTail() ) / ( profile.pathLength() * comparison.profile.pathLength() ) );
}

double Branch :: measureRadAngle( size_t i, size_t j ) {
    return acos( ( children[0]->getTipToTail() * children[1]->getTipToTail() ) / ( children[0]->profile.pathLength() * children[1]->profile.pathLength() ) );
}

//=============================================================================

size_t Branch :: getNumChildren() { return children.size(); }

size_t Branch :: getNumLeaves() { return leaves.size(); }

double Branch :: getDiameter() { return diameter; }

//=============================================================================

void Branch :: print() {
    cout << endl << "Curve Profile:" << endl;
    profile.print();

    cout << endl << " Leaves (" << getNumLeaves() << "):" << endl;
    for( auto &leaf : leaves ) {
        leaf.print();
    }

    cout << endl << " Children (" << getNumChildren() << "):" << endl;
    for( auto &child : children ) {
        child->print();
    }
}

///////////////////////////////////////////////////////////////////////////////

Branch :: CurveProfile :: CurveProfile( Point &baseIn, Direction &lengthIn )
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

double Branch :: CurveProfile :: measureRadAngle( CurveProfile &comparison ) {
    return length*comparison.length;
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

///////////////////////////////////////////////////////////////////////////////

Leaf :: Leaf( Point &baseIn, Direction &meridianIn, double occlusionIn ) 
:   base(baseIn),
    meridian(meridianIn),
    occlusion(occlusionIn) {}

Point Leaf :: getEnd() { return base + meridian; }

void Leaf :: print() {
    cout << "occlusion = " << occlusion << endl;

    cout << "base point: ";
    
    base.print();

    cout << "length vector: ";
    meridian.print();

    cout << "total length = " << meridian.length() << endl;

    cout << "end point: ";
    getEnd().print();
}