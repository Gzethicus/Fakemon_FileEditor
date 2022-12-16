#ifndef PACKAGEEXPLORER__H
#define PACKAGEEXPLORER__H

#include <string>
#include <unordered_map>
#include <vector>
#include <jsoncpp/json/json.h>

#include "Package.hpp"

using namespace std;

class PackageExplorer {
    //Attributes
private:
    Package* package;
    int index[4];
    int depth;
    string fileName;

public:
    PackageExplorer(string file);
    void display(bool clearScreen);
    void up();
    void down();
    bool enter();
    void leave();
    void navByName();
    void erase();

private:
    void save();
};

#endif