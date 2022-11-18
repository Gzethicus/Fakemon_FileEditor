#include "CreaturePackage.hpp"
#include <memory>

using namespace std;

CreaturePackage::CreaturePackage () : creatures{unordered_map<string, Creature>()}{}

CreaturePackage::CreaturePackage (string json) {
    Json::CharReaderBuilder builder;
    unique_ptr<Json::CharReader> reader = unique_ptr<Json::CharReader> (builder.newCharReader());
    Json::Value val {};
    string err {};
    this->creatures = unordered_map<string, Creature>();

    reader->parse(json.c_str(), json.c_str() + json.length(), &val, &err);
    this->creatures.reserve(val.size());

    for (Json::ValueIterator creature = val.begin(); creature != val.end(); creature++){
        this->creatures[creature.name()] = Creature(val[creature.name()]);
    }
}

vector<string> CreaturePackage::getNames () {
    vector<string> keys;
    keys.reserve(this->creatures.size());

    for(auto key : this->creatures)
        keys.push_back(key.first);
    
    return keys;
}

Creature* CreaturePackage::get (string name){
    return &(this->creatures[name]);
}

Json::Value CreaturePackage::jsonExport (){
    Json::Value package;

    for(auto key : this->creatures)
        package[key.first] = key.second.jsonExport();
    
    return package;
}

void CreaturePackage::addCreature (string name, Creature creature){
    this->creatures[name] = creature;
}
