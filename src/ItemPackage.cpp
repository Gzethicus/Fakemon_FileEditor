#include "ItemPackage.hpp"
#include <memory>

using namespace std;

ItemPackage::ItemPackage () : items{unordered_map<string, Item>()}{}

ItemPackage::ItemPackage (string json) {
    Json::CharReaderBuilder builder;
    unique_ptr<Json::CharReader> reader = unique_ptr<Json::CharReader> (builder.newCharReader());
    Json::Value val {};
    string err {};
    this->items = unordered_map<string, Item>();

    reader->parse(json.c_str(), json.c_str() + json.length(), &val, &err);
    this->items.reserve(val.size());

    for (Json::ValueIterator item = val.begin(); item != val.end(); item++){
        this->items[item.name()] = Item(val[item.name()]);
    }
}

vector<string> ItemPackage::getNames () {
    vector<string> keys;
    keys.reserve(this->items.size());

    for(auto key : this->items)
        keys.push_back(key.first);
    
    return keys;
}

Item* ItemPackage::get (string name){
    return &(this->items[name]);
}

Json::Value ItemPackage::jsonExport (){
    Json::Value package;

    for(auto key : this->items)
        package[key.first] = key.second.jsonExport();
    
    return package;
}

void ItemPackage::addItem (string name, Item item){
    this->items[name] = item;
}
