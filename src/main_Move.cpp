#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>

#include "Move.hpp"
#include "Package.hpp"

using namespace std;


int main(int argc,char* argv[]) {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "";

    Move* test = new Move();
    test->setMax(2);
    test->setPower(90);
    test->setPriority(true);
    test->setSprite("DefaultMoveSprite/Water_Bolt");
    test->setType("DefaultType/Abyss");

    Move* test2 = new Move();
    test2->setMax(1);
    test2->setPower(130);
    test2->setPriority(false);
    test2->setSprite("DefaultMoveSprite/Fire_Blast");
    test2->setType("DefaultType/Infernal");

    Package testPackage = Package(3);
    testPackage.addElement("Water_Bolt", test);
    testPackage.addElement("Fire_Blast", test2);

    cout << "test:\n" << test->getFormattedStats();
    cout << "test2:\n" << test2->getFormattedStats();
    cout << Json::writeString(builder, test->jsonExport()) << endl;
    cout << Json::writeString(builder, testPackage.jsonExport()) << endl;

    return 0;
}
