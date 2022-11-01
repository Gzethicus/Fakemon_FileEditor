#ifndef IPACKAGE__H
#define IPACKAGE__H

#include <string>
#include <vector>

using namespace std;

class IPackage{
    public:
        virtual vector<string> getNames() = 0;
        virtual Json::Value jsonExport() = 0;
};
#endif
