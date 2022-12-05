#include <sstream>
#include <ncurses.h>
#include <memory>
#include "Package.hpp"


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
    this->elements.reserve(val.size() - 1);

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

void Package::display (int indexes[3], stringstream& ss) {
    int i = 0;
    if (indexes[0] > (int)this->order.size()){
        indexes[0] = this->order.size();
    }
    for (string element : this->order) {
        if (indexes[0] == i++) {
            ss << ">" << element << "\n";
            this->elements[element]->display(&(indexes[1]), ss);
        } else
            ss << element << "\n";
    }
    if (indexes[0] == this->order.size())
        ss << ">";
    ss << "New\n";
}

bool Package::prompt(int indexes[3]) {
    if (indexes[0] == this->order.size()){
        char* val = (char*)calloc(32, sizeof(char));
        getstr(val);
        this->addNew(val);
        return true;
    }
    if (indexes[1] == -1)
        return false;
    return this->elements[*next(this->order.cbegin(), indexes[0])]->prompt(&indexes[1]);
}

void Package::erase(int indexes[3]) {
    int i = 0;
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
            if (indexes[0] == i++)
                this->elements[element]->erase(&(indexes[1]));
        }
    }
}
