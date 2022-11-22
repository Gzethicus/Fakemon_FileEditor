#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>

#include "Creature.hpp"
#include "Package.hpp"

using namespace std;


int main(int argc,char* argv[]) {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "";

    Creature* test = new Creature();
    test->setStat(1, 120);
    test->setStat(2, 60);
    test->setStat(3, 120);
    test->setMove(0, "DefaultMoves/Fire Blast");
    test->setType("DefaultTypes/Fire");

    Creature* test2 = new Creature();
    test2->setStat(0, 120);
    test2->setStat(1, 70);
    test2->setStat(2, 120);
    test2->setStat(3, 90);
    test2->setMove(0, "DefaultMoves/Leaf Blower");
    test2->setType("DefaultTypes/Grass");

    Package testPackage = Package(0);
    testPackage.addElement("Fire Wasp", test);
    testPackage.addElement("Grass Tortoise", test2);

    cout << "test:\n" << test->getFormattedStats();
    cout << "test2:\n" << test2->getFormattedStats();
    cout << Json::writeString(builder, test->jsonExport()) << endl;
    cout << Json::writeString(builder, testPackage.jsonExport()) << endl;

    Package testPackage2 = Package(0, Json::writeString(builder, testPackage.jsonExport()));

    return 0;
}
