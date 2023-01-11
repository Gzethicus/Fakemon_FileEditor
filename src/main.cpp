#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>
#include <ncurses.h>
#include <termios.h>

#include "Aura.hpp"
#include "Move.hpp"
#include "Trigger.hpp"
#include "Item.hpp"
#include "Type.hpp"
#include "Creature.hpp"
#include "Package.hpp"
#include "PackageExplorer.hpp"

#define STDIN_FILENO 0
#define KEY_DEL 0512
#define KEY_BSPACE 0012

int main(int argc,char* argv[]) {
    PackageExplorer* explorer;
    if (argc < 2) {
        cout << "Invalid use, call using the following command :\n./file-editor <fileName> [if newfile : <filetype:0-5>]\n";
        return 1;
    } else if (argc < 3) {
        try {
            explorer = new PackageExplorer(argv[1]);
        } catch(runtime_error) {
            cout << "File not found. To create a new file add the file type as argument (0-5).\n";
            return 1;
        }
    } else {
        explorer = new PackageExplorer(argv[1], stoi(argv[2]));
    }
    initscr();
    keypad(stdscr, true);

    int ch;
    
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    char c,d,e;
    bool keepGoing = true;

    while (keepGoing){
        explorer->display(true);
        ch = getch();
        switch (ch){
            case KEY_UP:
                explorer->up();
                break;
            case KEY_DOWN:
                explorer->down();
                break;
            case KEY_RIGHT:
                keepGoing = explorer->enter();
                break;
            case KEY_LEFT:
                explorer->leave();
                break;
            case KEY_ENTER:
            case KEY_BSPACE:
                explorer->navByName();
                break;
            case KEY_DEL:
                explorer->erase();
                break;
            default:
                printw("key pressed : %d\n", ch);
                getch();
                break;
        }
    }
    
    endwin();
    return 0;
}