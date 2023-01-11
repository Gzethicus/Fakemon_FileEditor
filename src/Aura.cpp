#include "Aura.hpp"

using namespace std;

Aura::Aura() : targetSelf{false}, targetStat{0}, value{0}{}

Aura::Aura (Json::Value val){
    this->targetSelf = val["targetSelf"].asBool();
    this->targetStat = val["stat"].asInt();
    this->value = val["value"].asInt();
}

Json::Value Aura::jsonExport (){
    Json::Value json;
    json["targetSelf"] = this->targetSelf;
    json["stat"] = this->targetStat;
    json["value"] = this->value;
    return json;
}

void Aura::display(int indexes[2], stringstream& ss){
    if (indexes[0] > 2)
        indexes[0] = 2;
    ss << "\t";
    if (indexes[0] == 0)
        ss << ">";
    ss << "target :\t" << this->getStringTarget() << "\n";

    ss << "\t";
    if (indexes[0] == 1)
        ss << ">";
    ss << "stat :\t\t" << this->getStringStat() << "\n";

    ss << "\t";
    if (indexes[0] == 2)
        ss << ">";
    ss << (indexes[0] == 2 ? "value :\t" : "value :\t\t") << to_string(this->value) << "%\n";
}

void Aura::setField(int indexes[2], string value){
    switch (indexes[0]){
        case 0:
            this->targetSelf = !value.empty();
            break;
        case 1:
            this->targetStat = stoi(value);
            break;
        case 2:
            this->value = stoi(value);
            break;
    }
}

bool Aura::prompt(int indexes[2]){
    switch (indexes[0]){
        case 0:
            this->targetSelf ^= true;
            break;
        case 1:
            this->targetStat = (this->targetStat + 1) % 4;
            break;
        case 2:
            printw(">");
            char* val = (char*)calloc(32, sizeof(char));
            getstr(val);
            this->value = stof(val);
            free(val);
            break;
    }
    return true;
}

void Aura::erase(int indexes[2]) {

}
#pragma region getset
inline string Aura::getStringTarget (){
    return this->targetSelf ? "Self" : "Opponent";
}

inline string Aura::getStringStat (){
    switch (this->targetStat){
        case 0:
            return "HP";
        case 1:
            return "Atk";
        case 2:
            return "Def";
        case 3:
            return "Spd";
        default:
            return "Undefined";
    }
}

void Aura::setTarget (bool self){
    this->targetSelf = self;
}

void Aura::setTargetStat (int stat){
    this->targetStat = stat;
}

void Aura::setValue (int value){
    this->value = value;
}
#pragma endregion getset
