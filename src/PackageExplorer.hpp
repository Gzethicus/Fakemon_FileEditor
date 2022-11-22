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
    int index[3];
    int depth;

public:
    PackageExplorer(string file);
    void display();
    void up();
    void down();
    void enter();
    void leave();
};

#endif