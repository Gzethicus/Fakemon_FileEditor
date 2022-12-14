#include <memory>
#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include "PackageExplorer.hpp"
#include "Package.hpp"

using namespace std;

PackageExplorer::PackageExplorer(string fileName): index{0, 0, -1, -1}, depth{1} {
    this->fileName = fileName;
    struct stat buffer;
    if (stat (fileName.c_str(), &buffer) == 0) {
        fstream file;
        file.open(fileName, fstream::in);
        string json;
        getline(file, json, '\n');
        this->package = new Package(json);
        file.close();
    } else {
        this->package = new Package(0);
    }
}

void PackageExplorer::display(bool clearScreen) {
    if (clearScreen) {
        clear();
        refresh();
    }
    stringstream ss;
    this->package->display(&(this->index[1]), ss);
    printw(ss.str().c_str());
    printw("\n");
    if (depth == 0) {
        string promptSave;
        if (this->index[0] == 0)
            promptSave += ">";
        promptSave += "Save and quit\n";
        if (this->index[0] == 1)
            promptSave += ">";
        promptSave += "Quit without saving\n";
        if (this->index[0] == 2)
            promptSave += ">";
        promptSave += "Cancel\n";
        printw(promptSave.c_str());
    }
}

void PackageExplorer::up() {
    index[depth]--;
    if (index[depth] < 0)
        index[depth] = 0;
}

void PackageExplorer::down() {
    index[depth]++;
    if (index[0] > 2) {
        index[0] = 2;
    }
}

bool PackageExplorer::enter() {
    if (this->depth == 0) {
        if (this->index[0] == 0) {
            this->save();
            return false;
        }
        if (this->index[0] == 1)
            return false;
        this->index[0] = 0;
    }
    if (!this->package->prompt(&(this->index[1])))
        index[++depth]++;
    return true;
}

void PackageExplorer::leave() {
    index[depth--] = -1;
    if (depth < 0) {
        depth = 0;
        index[0] = 0;
    }
}

void PackageExplorer::erase() {
    if (this->depth == 0)
        return;
    this->package->erase(&(this->index[1]));
}

void PackageExplorer::save() {
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "";

    fstream file;
    file.open(this->fileName, fstream::out);
    file << Json::writeString(builder, this->package->jsonExport()) << endl;
    file.close();
}
