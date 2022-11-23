#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>
#include <termios.h>

#include "Effect.hpp"
#include "Move.hpp"
#include "Trigger.hpp"
#include "Item.hpp"
#include "Type.hpp"
#include "Creature.hpp"
#include "Package.hpp"
#include "PackageExplorer.hpp"

#define STDIN_FILENO 0

int main(int argc,char* argv[]) {
    PackageExplorer* explorer;
    if (argc != 2) {
        cout << "Invalid use, call using the following command :\n./file-editor <fileName>\n";
        return 1;
    } else {
        explorer = new PackageExplorer(argv[1]);
    }

    int ch;
    
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    char c,d,e;
    bool keepGoing = true;

    while (keepGoing){
        system("clear");
        explorer->display();
        cin >> c;
        cin >> d;
        cin >> e;
        if ((c==27)&&(d=91)) {
            if (e==65)
                explorer->up();
            if (e==66)
                explorer->down();
            if (e==67)
                explorer->enter();
            if (e==68){
                if (!explorer->leave()){
                    system("clear");
                    keepGoing = false;
                }
            }
        }
    }
    
    return 0;
}