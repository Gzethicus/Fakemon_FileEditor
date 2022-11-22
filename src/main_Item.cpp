#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>

#include "Item.hpp"
#include "Package.hpp"

using namespace std;


int main(int argc,char* argv[]) {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "";

    Item* test = new Item();
    test->setEffect("DefaultEffect/AtkBuf");
    test->setTrigger("DefaultTriggers/Low_HP");

    Item* test2 = new Item();
    test2->setEffect("DefaultEffect/AtkBuf");
    test2->setTrigger("DefaulTriggers/High_ATK");

    Package testPackage = Package(2);
    testPackage.addElement("Berserker's scarf", test);
    testPackage.addElement("Flask of absolute power", test2);

    cout << "test:\n" << test->getFormattedStats();
    cout << "test2:\n" << test2->getFormattedStats();
    cout << Json::writeString(builder, test->jsonExport()) << endl;
    cout << Json::writeString(builder, testPackage.jsonExport()) << endl;

    Package testPackage2 = Package(2, Json::writeString(builder, testPackage.jsonExport()));

    return 0;
}
