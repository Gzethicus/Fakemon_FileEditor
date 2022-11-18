#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>

#include "Creature.hpp"
#include "CreaturePackage.hpp"

using namespace std;


int main(int argc,char* argv[]) {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "";

    Creature test = Creature();
    test.setStat(1, 120);
    test.setStat(2, 60);
    test.setStat(3, 120);
    test.setMove(0, "DefaultMoves/Fire Blast");
    test.setType("DefaultTypes/Fire");

    Creature test2 = Creature();
    test2.setStat(0, 120);
    test2.setStat(1, 70);
    test2.setStat(2, 120);
    test2.setStat(3, 90);
    test2.setMove(0, "DefaultMoves/Leaf Blower");
    test2.setType("DefaultTypes/Grass");

    CreaturePackage testPackage = CreaturePackage();
    testPackage.addCreature("Fire Wasp", test);
    testPackage.addCreature("Grass Tortoise", test2);

    cout << "test:\n" << test.getFormattedStats();
    cout << "test2:\n" << test2.getFormattedStats();
    cout << Json::writeString(builder, test.jsonExport()) << endl;
    cout << Json::writeString(builder, testPackage.jsonExport()) << endl;

    CreaturePackage testPackage2 = CreaturePackage(Json::writeString(builder, testPackage.jsonExport()));

    return 0;
}
