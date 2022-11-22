#include <iostream>
#include <memory>
#include "Package.hpp"


using namespace std;

Package::Package (int type) : elements{unordered_map<string, IPackageElement*>()}, type(type) {}

Package::Package (int type, string json) : type(type) {
    Json::CharReaderBuilder builder;
    unique_ptr<Json::CharReader> reader = unique_ptr<Json::CharReader> (builder.newCharReader());
    Json::Value val {};
    string err {};
    this->elements = unordered_map<string, IPackageElement*>();

    reader->parse(json.c_str(), json.c_str() + json.length(), &val, &err);
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
        this->order.push_back(element.name());
    }
}

vector<string> Package::getNames () {
    return this->order;
}

IPackageElement* Package::get (string name){
    return this->elements[name];
}

Json::Value Package::jsonExport (){
    Json::Value package;
    for(string key : this->order)
        package[key] = this->elements[key]->jsonExport();
    return package;
}

void Package::addElement (string name, IPackageElement* element){
    this->elements[name] = element;
    this->order.push_back(name);
}

void Package::display (int indexes[3]) {
    int* subindexes = &(indexes[1]);
    for (int i = 0; i < this->elements.size(); i++) {
        if (i == indexes[0]) {
            cout << ">" << this->order[i] << endl;
            this->elements[order[i]]->display(subindexes);
        } else
            cout << this->order[i] << endl;
    }
}
