#include <iostream>

#include "Effect.hpp"

using namespace std;


int main(int argc,char* argv[]) {
    Effect test = Effect();
    test.setOperator(0);
    test.setTarget(false);
    test.setValue(30.f);
    cout << test.getFormattedStats();
    cout << test.jsonExport() << endl;

    return 0;
}
