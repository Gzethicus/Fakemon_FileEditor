#include <iostream>
#include <memory>
#include "EffectPackage.hpp"

using namespace std;

EffectPackage::EffectPackage () : effects{unordered_map<string, Effect>()}{}

EffectPackage::EffectPackage (string json) {
    Json::CharReaderBuilder builder;
    unique_ptr<Json::CharReader> reader = unique_ptr<Json::CharReader> (builder.newCharReader());
    Json::Value val {};
    string err {};
    this->effects = unordered_map<string, Effect>();

    reader->parse(json.c_str(), json.c_str() + json.length(), &val, &err);
    this->effects.reserve(val.size());

    for (Json::ValueIterator effect = val.begin(); effect != val.end(); effect++){
        this->effects[effect.name()] = Effect(val[effect.name()]);
        this->order.push_back(effect.name());
    }
}

vector<string> EffectPackage::getNames () {
    return this->order;
}

Effect* EffectPackage::get (string name){
    return &(this->effects[name]);
}

Json::Value EffectPackage::jsonExport (){
    Json::Value package;

    for(auto key : this->effects)
        package[key.first] = key.second.jsonExport();
    
    return package;
}

void EffectPackage::addEffect (string name, Effect effect){
    this->effects[name] = effect;
    this->order.push_back(name);
}

void EffectPackage::display (int indexes[3]) {
    int subindexes[2] = {indexes[1], indexes[2]};
    for (int i = 0; i < this->effects.size(); i++) {
        if (i == indexes[0]) {
            cout << ">" << this->order[i] << endl;
            this->effects[order[i]].display(subindexes);
        } else
            cout << this->order[i] << endl;
    }
}
