#include <iostream>
#include "branches.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[]){
    cout << endl << "Beginning branch library test run." << endl;

    // Adding Child
    cout << endl << "Beginning add child test." << endl;
    Branch mainBranch;
    cout << "Initial conditions, main branch: " << endl;
    mainBranch.print();

    cout << endl << "Making unique pointer to new branch." << endl;
    auto childPtr = std::make_unique<Branch>();
    cout << "New branch initial conditions:" << endl;
    childPtr->print();

    cout << endl << "Moving unique pointer to main branch." << endl;
    mainBranch.addChild(childPtr);

    cout << endl << "Add complete." << endl;    
    cout << "Final conditions, main branch:" << endl;
    mainBranch.print();

    return 0;
}