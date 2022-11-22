#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>

#include "Trigger.hpp"
#include "Package.hpp"

using namespace std;


int main(int argc,char* argv[]) {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "";

    Trigger* test = new Trigger();
    test->setThreshold(50);

    Trigger* test2 = new Trigger();
    test2->setStat(1);
    test2->setThreshold(130);

    Package testPackage = Package(4);
    testPackage.addElement("Low_HP", test);
    testPackage.addElement("High_ATK", test2);

    cout << "test:\n" << test->getFormattedStats();
    cout << "test2:\n" << test2->getFormattedStats();
    cout << Json::writeString(builder, test->jsonExport()) << endl;
    cout << Json::writeString(builder, testPackage.jsonExport()) << endl;

    return 0;
}
