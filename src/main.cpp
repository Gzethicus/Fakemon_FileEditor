#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>

#include "Effect.hpp"
#include "Move.hpp"
#include "Trigger.hpp"
#include "Item.hpp"
#include "Type.hpp"
#include "Creature.hpp"
#include "Package.hpp"
#include "PackageExplorer.hpp"

int main(int argc,char* argv[]) {
    PackageExplorer* explorer;
    if (argc != 2) {
        cout << "Invalid use, call using the following command :\n./file-editor <fileName>\n";
        return 1;
    } else {
        explorer = new PackageExplorer(argv[1]);
    }
    explorer->display();
    explorer->down();
    explorer->display();
    explorer->enter();
    explorer->display();
    explorer->down();
    explorer->down();
    explorer->display();
    explorer->leave();
    explorer->display();
    explorer->enter();
    explorer->display();
    return 0;
}