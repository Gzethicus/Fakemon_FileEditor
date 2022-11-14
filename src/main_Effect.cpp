#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>

#include "Effect.hpp"
#include "EffectPackage.hpp"

using namespace std;


int main(int argc,char* argv[]) {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "";

    Effect test = Effect();
    test.setTarget(true);
    test.setTargetStat(1);
    test.setOperator(1);
    test.setValue(1.2f);

    Effect test2 = Effect();
    test2.setTarget(false);
    test2.setTargetStat(2);
    test2.setOperator(0);
    test2.setValue(-20.f);

    EffectPackage testPackage = EffectPackage();
    testPackage.addEffect("AtkBuf", test);
    testPackage.addEffect("DefDebuf", test2);

    cout << "test:\n";
    cout << test.getFormattedStats();
    cout << "test2:\n";
    cout << test2.getFormattedStats();
    cout << Json::writeString(builder, test.jsonExport()) << endl;
    cout << Json::writeString(builder, testPackage.jsonExport()) << endl;

    EffectPackage testPackage2 = EffectPackage(Json::writeString(builder, testPackage.jsonExport()));
    testPackage2.get("AtkBuf")->setOperator(0);
    testPackage2.get("DefDebuf")->setValue(-25.f);
    cout << Json::writeString(builder, testPackage2.jsonExport()) << endl;

    return 0;
}
