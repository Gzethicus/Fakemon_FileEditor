#include "TriggerPackage.hpp"
#include <memory>

using namespace std;

TriggerPackage::TriggerPackage () : triggers{unordered_map<string, Trigger>()}{}

TriggerPackage::TriggerPackage (string json) {
    Json::CharReaderBuilder builder;
    unique_ptr<Json::CharReader> reader = unique_ptr<Json::CharReader> (builder.newCharReader());
    Json::Value val {};
    string err {};
    this->triggers = unordered_map<string, Trigger>();

    reader->parse(json.c_str(), json.c_str() + json.length(), &val, &err);
    this->triggers.reserve(val.size());

    for (Json::ValueIterator trigger = val.begin(); trigger != val.end(); trigger++){
        this->triggers[trigger.name()] = Trigger(val[trigger.name()]);
    }
}

vector<string> TriggerPackage::getNames () {
    vector<string> keys;
    keys.reserve(this->triggers.size());

    for(auto key : this->triggers)
        keys.push_back(key.first);
    
    return keys;
}

Trigger* TriggerPackage::get (string name){
    return &(this->triggers[name]);
}

Json::Value TriggerPackage::jsonExport (){
    Json::Value package;

    for(auto key : this->triggers)
        package[key.first] = key.second.jsonExport();
    
    return package;
}

void TriggerPackage::addTrigger (string name, Trigger trigger){
    this->triggers[name] = trigger;
}
