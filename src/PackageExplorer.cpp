#include <memory>
#include <fstream>
#include <iostream>
#include "PackageExplorer.hpp"
#include "Package.hpp"

using namespace std;

PackageExplorer::PackageExplorer(string fileName): index{0, -1, -1}, depth{0} {
    fstream file;
    file.open(fileName, fstream::in);
    string sType;
    int type = -1;
    string json;
    getline(file, sType, '\n');
    getline(file, json, '\n');
    if (sType == "Creature")
        type = 0;
    else if (sType == "Effect")
        type = 1;
    else if (sType == "Item")
        type = 2;
    else if (sType == "Move")
        type = 3;
    else if (sType == "Trigger")
        type = 4;
    else if (sType == "Type")
        type = 5;
    this->package = new Package(type, json);
}

void PackageExplorer::display() {
    this->package->display(this->index);
    cout << endl;
}

void PackageExplorer::up() {
    index[depth]--;
}

void PackageExplorer::down() {
    index[depth]++;
}

void PackageExplorer::enter() {
    index[++depth]++;
}

void PackageExplorer::leave() {
    index[depth--] = -1;
}
