#include <iostream>
#include "branches.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[]){
    cout << endl << "Beginning branch library test run." << endl;

    cout << endl << "Initializing mainBranch." << endl;
    Branch mainBranch;
    cout << "Initial conditions, main branch: " << endl;
    mainBranch.print();

    cout << endl << "Making unique pointer to new branch." << endl;
    auto childPtr = std::make_unique<Branch>();
    cout << "New branch initial conditions:" << endl;
    childPtr->print();

    cout << endl << "Using addChild to add unique pointer to mainBranch." << endl;
    mainBranch.addChild(childPtr);

    cout << endl << "Add complete." << endl;    
    cout << "Final conditions, main branch:" << endl;
    mainBranch.print();

    cout << endl << "Using addChild to add default new branch to mainBranch." << endl;
    mainBranch.addChild();

    cout << endl << "Add complete." << endl;    
    cout << "Final conditions, main branch:" << endl;
    mainBranch.print();

    cout << "Angle between child branches = ";
    cout << mainBranch.measureRadAngle(0,1) << endl;

    return 0;
}