#include "EffectPackage.hpp"
#include <memory>

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
    }
}

vector<string> EffectPackage::getNames () {
    vector<string> keys;
    keys.reserve(this->effects.size());

    for(auto key : this->effects)
        keys.push_back(key.first);
    
    return keys;
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
}
