#include "EffectPackage.hpp"

using namespace std;

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

string EffectPackage::jsonExport (){
    string json = "{";

    for(auto key : this->effects)
        json += key.first + ":" + key.second.jsonExport() + ",";
    
    json += "}\n";
    return json;
}

void EffectPackage::addEffect (string name, Effect effect){
    this->effects[name] = effect;
}
