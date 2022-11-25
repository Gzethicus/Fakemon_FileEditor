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

void PackageExplorer::display(bool clearScreen) {
    if (refresh){
        clear();
        refresh();
    }
    printw(this->package->display(this->index).str().c_str());
    printw("\n");
}

void PackageExplorer::up() {
    index[depth]--;
    if (index[depth] < 0)
        index[depth] = 0;
}

void PackageExplorer::down() {
    index[depth]++;
}

void PackageExplorer::enter() {
    if (!this->package->prompt(this->index))
        index[++depth]++;
}

bool PackageExplorer::leave() {
    index[depth--] = -1;
    if (depth < 0)
        return false;
    return true;
}
