#include "EffectPackage.hpp"
#include <iostream>

using namespace std;

EffectPackage::EffectPackage () : effects{unordered_map<string, Effect>()}{}

EffectPackage::EffectPackage (string json) {
    Json::Reader reader;
    Json::Value val;
    this->effects = unordered_map<string, Effect>();
    this->effects.reserve(val.size());
    cout << "allocated\n";
    if (reader.parse(json, val, true))
        cout << "parsed";
    else 
        cout << reader.getFormattedErrorMessages();
    for (Json::ValueIterator effect = val.begin(); effect != val.end(); effect++){
        this->effects[effect.key().asString()] = Effect(val[effect.index()]);
        cout << effect.name();
    }
}

vector<string> EffectPackage::getNames (){
    vector<string> keys;
    keys.reserve(this->effects.size());

    for(auto key : this->effects)
        keys.push_back(key.first);
    
    return keys;
}

Effect EffectPackage::get (string name){
    return this->effects[name];
}

Json::Value EffectPackage::jsonExport (){
    Json::Value package;

    for(auto key : this->effects)
        package[key.first] = key.second.jsonExport();
    
    return package;
}

void EffectPackage::addEffect (string name, Effect effect){
    this->effects[name] = effect;
}
