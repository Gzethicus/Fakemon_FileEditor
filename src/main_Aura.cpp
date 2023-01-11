#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>

#include "Aura.hpp"
#include "Package.hpp"

using namespace std;


int main(int argc,char* argv[]) {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "";

    Aura* test = new Aura();
    test->setTarget(true);
    test->setTargetStat(1);
    test->setOperator(1);
    test->setValue(1.2f);

    Aura* test2 = new Aura();
    test2->setTarget(false);
    test2->setTargetStat(2);
    test2->setOperator(0);
    test2->setValue(-20.f);

    Package testPackage = Package(1);
    testPackage.addElement("AtkBuf", test);
    testPackage.addElement("DefDebuf", test2);

    cout << "test:\n" << test->getFormattedStats();
    cout << "test2:\n" << test2->getFormattedStats();
    cout << Json::writeString(builder, test->jsonExport()) << endl;
    cout << Json::writeString(builder, testPackage.jsonExport()) << endl;

    Package testPackage2 = Package(1, Json::writeString(builder, testPackage.jsonExport()));
    testPackage2.get("AtkBuf")->setField(2, "0");
    testPackage2.get("DefDebuf")->setField(3, "-25.f");
    cout << Json::writeString(builder, testPackage2.jsonExport()) << endl;

    return 0;
}
