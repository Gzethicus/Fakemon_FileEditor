#include <sstream>
#include <sys/stat.h>
#include <fstream>
#include <ncurses.h>
#include <memory>
#include "Package.hpp"

#define SPECIAL_LINES 2

using namespace std;

Package::Package (int type) : elements{unordered_map<string, IPackageElement*>()}, type(type) {}

Package::Package (string json) {
    Json::CharReaderBuilder builder;
    unique_ptr<Json::CharReader> reader = unique_ptr<Json::CharReader> (builder.newCharReader());
    Json::Value val {};
    string err {};
    this->elements = unordered_map<string, IPackageElement*>();

    reader->parse(json.c_str(), json.c_str() + json.length(), &val, &err);
    this->type = val["Type"].asInt();
    val.removeMember("Type");

    Json::Value dependencies = val["Dependencies"]["Moves"];
    for (Json::ValueIterator dependency = dependencies.begin(); dependency != dependencies.end(); dependency++) {
        this->moveDependencies.insert(dependencies[dependency.index()].asString());
    }
    dependencies = val["Dependencies"]["Types"];
    for (Json::ValueIterator dependency = dependencies.begin(); dependency != dependencies.end(); dependency++) {
        this->typeDependencies.insert(dependencies[dependency.index()].asString());
    }
    dependencies = val["Dependencies"]["Effects"];
    for (Json::ValueIterator dependency = dependencies.begin(); dependency != dependencies.end(); dependency++) {
        this->effectDependencies.insert(dependencies[dependency.index()].asString());
    }
    dependencies = val["Dependencies"]["Triggers"];
    for (Json::ValueIterator dependency = dependencies.begin(); dependency != dependencies.end(); dependency++) {
        this->triggerDependencies.insert(dependencies[dependency.index()].asString());
    }
    val.removeMember("Dependencies");
    this->elements.reserve(val.size());

    for (Json::ValueIterator element = val.begin(); element != val.end(); element++){
        switch (this->type) {
            case 0:
                this->elements[element.name()] = new Creature(val[element.name()]);
                break;
            case 1:
                this->elements[element.name()] = new Effect(val[element.name()]);
                break;
            case 2:
                this->elements[element.name()] = new Item(val[element.name()]);
                break;
            case 3:
                this->elements[element.name()] = new Move(val[element.name()]);
                break;
            case 4:
                this->elements[element.name()] = new Trigger(val[element.name()]);
                break;
            case 5:
                this->elements[element.name()] = new Type(val[element.name()]);
                break;
        }
        this->order.insert(element.name());
    }
}

set<string> Package::getNames () {
    return this->order;
}

IPackageElement* Package::get (string name) {
    return this->elements[name];
}

Json::Value Package::jsonExport () {
    Json::Value package;
    package["Type"] = this->type;
    if(this->moveDependencies.size() > 0) {
        package["Dependencies"]["Moves"] = Json::arrayValue;
        for(string dependency : this->moveDependencies) {
            package["Dependencies"]["Moves"].append(dependency);
        }
    }
    if(this->typeDependencies.size() > 0) {
        package["Dependencies"]["Types"] = Json::arrayValue;
        for(string dependency : this->typeDependencies) {
            package["Dependencies"]["Types"].append(dependency);
        }
    }
    if(this->effectDependencies.size() > 0) {
        package["Dependencies"]["Effects"] = Json::arrayValue;
        for(string dependency : this->effectDependencies) {
            package["Dependencies"]["Effects"].append(dependency);
        }
    }
    if(this->triggerDependencies.size() > 0) {
        package["Dependencies"]["Triggers"] = Json::arrayValue;
        for(string dependency : this->triggerDependencies) {
            package["Dependencies"]["Triggers"].append(dependency);
        }
    }
    for(string key : this->order)
        package[key] = this->elements[key]->jsonExport();
    return package;
}

void Package::addNew(string name) {
    if (this->order.find(name) != this->order.end())
        return;
    IPackageElement* element;
    switch (this->type){
        case 0: // Creature
            element = new Creature();
            break;
        case 1: // Effect
            element = new Effect();
            break;
        case 2: // Item
            element = new Item();
            break;
        case 3: // Move
            element = new Move();
            break;
        case 4: // Trigger
            element = new Trigger();
            break;
        case 5: // Type
            element = new Type();
            break;
    }
    this->addElement(name, element);
}

void Package::addElement (string name, IPackageElement* element) {
    this->elements[name] = element;
    this->order.insert(name);
}

void Package::addDependency(string name) {
    struct stat buffer;
    if (stat ((name + ".json").c_str(), &buffer) == 0) {
        fstream file;
        file.open(name + ".json", fstream::in);
        string json;
        Json::CharReaderBuilder builder;
        Json::Value val {};
        string err {};
        Json::parseFromStream(builder, file, &val, &err);
        file.close();
        switch(val["Type"].asInt()) {
            case 1:
                this->effectDependencies.insert(name);
                break;
            case 3:
                this->moveDependencies.insert(name);
                break;
            case 4:
                this->triggerDependencies.insert(name);
                break;
            case 5:
                this->typeDependencies.insert(name);
                break;
        }
    }
}

void Package::display (int indexes[3], stringstream& ss) {
    int i = 0;
    if (indexes[0] > (int)this->order.size() - 1 + SPECIAL_LINES){
        indexes[0] = this->order.size() - 1 + SPECIAL_LINES;
    }
    if (indexes[0] == i++) {
        int j = 0;
        ss << ">Dependencies\n";
        for(string dependency : this->moveDependencies)
            ss << "\t" << ((j++ == indexes[1]) ? ">" : "") << dependency << "\n";
        for(string dependency : this->typeDependencies)
            ss << "\t" << ((j++ == indexes[1]) ? ">" : "") << dependency << "\n";
        for(string dependency : this->effectDependencies)
            ss << "\t" << ((j++ == indexes[1]) ? ">" : "") << dependency << "\n";
        for(string dependency : this->triggerDependencies)
            ss << "\t" << ((j++ == indexes[1]) ? ">" : "") << dependency << "\n";
        ss << "\t" << ((j++ == indexes[1]) ? ">" : "") << "New\n";
    } else {
        ss << "Dependencies\n";
    }
    for (string element : this->order) {
        if (indexes[0] == i++) {
            ss << ">" << element << "\n";
            this->elements[element]->display(&(indexes[1]), ss);
        } else
            ss << element << "\n";
    }
    if (indexes[0] == i++)
        ss << ">";
    ss << "New\n";
}

bool Package::prompt(int indexes[3]) {
    if (indexes[0] == this->order.size() - 1 + SPECIAL_LINES){
        printw(">");
        char* val = (char*)calloc(32, sizeof(char));
        getstr(val);
        this->addNew(val);
        return true;
    }
    if (indexes[1] == -1)
        return false;
    if (indexes[0] == 0) {
        if (indexes[1] == this->moveDependencies.size() + this->typeDependencies.size() + this->effectDependencies.size() + this->triggerDependencies.size()) {
            char* val = (char*)calloc(32, sizeof(char));
            getstr(val);
            this->addDependency(val);
            return true;
        }
    }
    return this->elements[*next(this->order.cbegin(), indexes[0] - 1)]->prompt(&indexes[1]);
}

void Package::erase(int indexes[3]) {
    int i = 1;
    if(indexes[1] == -1){
        for (string element : this->order) {
            if (indexes[0] == i++) {
                delete this->elements[element];
                this->order.erase(element);
                break;
            }
        }
    } else {
        for (string element : this->order) {
            if (indexes[0] == i++) {
                this->elements[element]->erase(&(indexes[1]));
                break;
            }
        }
    }
}
