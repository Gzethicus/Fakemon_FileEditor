#include "Type.hpp"
#include <memory>

using namespace std;

Type::Type() : factors{unordered_map<string, float>()}{}

Type::Type (Json::Value val){
    Json::CharReaderBuilder builder;
    unique_ptr<Json::CharReader> reader = unique_ptr<Json::CharReader> (builder.newCharReader());
    string err {};
    this->factors = unordered_map<string, float>();
    this->factors.reserve(val.size());

    for (Json::ValueIterator factor = val.begin(); factor != val.end(); factor++){
        this->factors[factor.name()] = val[factor.name()].asFloat();
    }
}

string Type::getFormattedStats (){
    string formatted = "";
    string type;
    int indent;
    for (auto key : this->factors) {
        type = key.first;
        indent = 2 - ((type.length() + 2) /8);  //compute the number of remaining indents to reach a 3 * 8 indent, accounting for " :" (2 chars)
        formatted += "\t" + type + " :" + string(indent, '\t') + to_string(key.second) + "\n";
    }
    return formatted;
}

Json::Value Type::jsonExport (){
    Json::Value json;
    for (auto key : this->factors)
        json[key.first] = key.second;
    return json;
}

void Type::display(int indexes[2]){
    int i = 0;
    int indent;
    string type;
    for (pair<string,float> key: this->factors){
        type = key.first;
        indent = 2 - ((type.length() + 2) /8);  //compute the number of remaining indents to reach a 3 * 8 indent, accounting for " :" (2 chars)
        cout << "\t";
        if (indexes[0] == i++)
            cout << ">";
        cout << type << " :" << string(indent, '\t') << to_string(key.second) << endl;
    }
}

void Type::setField(int indexes[2], string value){
    
}

#pragma region getset
void Type::setFactor (string type, float factor){
    this->factors[type] = factor;
}
#pragma endregion getset
