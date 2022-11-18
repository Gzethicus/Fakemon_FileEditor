#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>

#include "Type.hpp"
#include "TypePackage.hpp"

using namespace std;


int main(int argc,char* argv[]) {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "";

    Type test = Type();
    test.setFactor("Water", 2.f);
    test.setFactor("Fire", .5f);

    Type test2 = Type();
    test2.setFactor("Fire", 2.f);
    test2.setFactor("Grass", .5f);

    TypePackage testPackage = TypePackage();
    testPackage.addType("Grass", test);
    testPackage.addType("Water", test2);

    cout << "test:\n" << test.getFormattedStats();
    cout << "test2:\n" << test2.getFormattedStats();
    cout << Json::writeString(builder, test.jsonExport()) << endl;
    cout << Json::writeString(builder, testPackage.jsonExport()) << endl;

    TypePackage testPackage2 = TypePackage(Json::writeString(builder, testPackage.jsonExport()));

    return 0;
}
