#include <memory>
#include <fstream>
#include <iostream>
#include "PackageExplorer.hpp"
#include "CreaturePackage.hpp"
#include "EffectPackage.hpp"
#include "ItemPackage.hpp"
#include "MovePackage.hpp"
#include "TriggerPackage.hpp"
#include "TypePackage.hpp"

using namespace std;

PackageExplorer::PackageExplorer(string fileName): index{0, -1, -1}, depth{0} {
    fstream file;
    file.open(fileName, fstream::in);
    string type;
    string json;
    getline(file, type, '\n');
    getline(file, json, '\n');
    if (type == "Creature")
        //this->package = new CreaturePackage(json);
        int i;
    else if (type == "Effect")
        this->package = new EffectPackage(json);
    /*else if (type == "Item")
        this->package = new ItemPackage(json);
    else if (type == "Move")
        this->package = new MovePackage(json);
    else if (type == "Trigger")
        this->package = new TriggerPackage(json);
    else if (type == "Type")
        this->package = new TypePackage(json);*/
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
    index[++depth] = 0;
}

void PackageExplorer::leave() {
    index[depth--] = -1;
}
