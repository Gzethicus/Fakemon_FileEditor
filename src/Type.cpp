#include "Type.hpp"
#include <memory>

using namespace std;

Type::Type() : factors{unordered_map<string, float>()} {}

Type::Type (Json::Value val) {
    Json::CharReaderBuilder builder;
    unique_ptr<Json::CharReader> reader = unique_ptr<Json::CharReader> (builder.newCharReader());
    string err {};
    this->factors = unordered_map<string, float>();
    this->factors.reserve(val.size());

    for (Json::ValueIterator factor = val.begin(); factor != val.end(); factor++){
        this->factors[factor.name()] = val[factor.name()].asFloat();
        this->order.insert(factor.name());
    }
}

Json::Value Type::jsonExport () {
    Json::Value json;
    for (string type : this->order)
        json[type] = this->factors[type];
    return json;
}

void Type::display(int indexes[2], stringstream& ss) {
    int i = 0;
    int indent;
    if (indexes[0] > (int)this->order.size())
        indexes[0] = this->order.size();
    for (string type : this->order) {
        indent = 2 - ((type.length() + (indexes[0] == i ? 3 : 2)) /8);  //compute the number of remaining indents to reach a 3 * 8 indent, accounting for " :" (2 chars) and potentially ">" (1 more char)
        ss << "\t";
        if (indexes[0] == i++)
            ss << ">";
        ss << type << " :" << string(indent, '\t') << to_string(this->factors[type]) << "\n";
    }
    ss << "\t";
    if (indexes[0] == i)
        ss << ">";
    ss << "New type" << "\n";
}

bool Type::prompt(int indexes[2]) {
    printw(">");
    char* val = (char*)calloc(32, sizeof(char));
    getstr(val);
    if (indexes[0] == this->order.size()) {
        this->order.insert(val);
        this->factors[val] = 1.f;
    }
    else
        this->setField(indexes, val);
    free(val);
    return true;
}

void Type::erase(int indexes[2]) {

}

#pragma region getset
void Type::setField(int indexes[2], string value) {
    int i = 0;
    for (string type : this->order) {
        if (i++ == indexes[0]) {
            this->factors[type] = stof(value);
            return;
        }
    }
}

void Type::setFactor (string type, float factor) {
    this->factors[type] = factor;
    this->order.insert(type);
}
#pragma endregion getset
