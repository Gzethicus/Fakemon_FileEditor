#include "TypePackage.hpp"
#include <memory>

using namespace std;

TypePackage::TypePackage () : types{unordered_map<string, Type>()}{}

TypePackage::TypePackage (string json) {
    Json::CharReaderBuilder builder;
    unique_ptr<Json::CharReader> reader = unique_ptr<Json::CharReader> (builder.newCharReader());
    Json::Value val {};
    string err {};
    this->types = unordered_map<string, Type>();

    reader->parse(json.c_str(), json.c_str() + json.length(), &val, &err);
    this->types.reserve(val.size());

    for (Json::ValueIterator type = val.begin(); type != val.end(); type++){
        this->types[type.name()] = Type(val[type.name()]);
    }
}

vector<string> TypePackage::getNames () {
    vector<string> keys;
    keys.reserve(this->types.size());

    for(auto key : this->types)
        keys.push_back(key.first);
    
    return keys;
}

Type* TypePackage::get (string name){
    return &(this->types[name]);
}

Json::Value TypePackage::jsonExport (){
    Json::Value package;

    for(auto key : this->types)
        package[key.first] = key.second.jsonExport();
    
    return package;
}

void TypePackage::addType (string name, Type type){
    this->types[name] = type;
}
