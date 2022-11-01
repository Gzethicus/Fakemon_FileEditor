#include <iostream>
#include <jsoncpp/json/json.h>

#include "Effect.hpp"
#include "EffectPackage.hpp"

using namespace std;


int main(int argc,char* argv[]) {
    Json::FastWriter fastWriter;

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
    cout << fastWriter.write(test.jsonExport());
    cout << fastWriter.write(testPackage.jsonExport());

    EffectPackage testPackage2 = EffectPackage(fastWriter.write(testPackage.jsonExport()));

    return 0;
}
