#include <iostream>
#include "Effect.hpp"

using namespace std;

Effect::Effect() : targetSelf{false}, targetStat{0}, operation{0}, value{0.f}{}

Effect::Effect (Json::Value val){
    this->targetSelf = val["targetSelf"].asBool();
    this->targetStat = val["stat"].asInt();
    this->operation = val["operation"].asInt();
    this->value = val["value"].asFloat();
}

string Effect::getFormattedStats (){
    string formatted = "\ttarget :\t" + this->getStringTarget() + "\n";
    formatted += "\tstat :\t\t" + this->getStringStat() + "\n";
    formatted += "\toperation :\t" + this->getStringOperator() + "\n";
    formatted += "\tvalue :\t\t" + to_string(this->value) + "\n";
    return formatted;
}

Json::Value Effect::jsonExport (){
    Json::Value json;
    json["targetSelf"] = this->targetSelf;
    json["stat"] = this->targetStat;
    json["operation"] = this->operation;
    json["value"] = this->value;
    return json;
}

#pragma region getset
inline string Effect::getStringOperator (){
    switch (this->operation){
        case 0:
            return "Add";
        case 1:
            return "Mult";
        default:
            return "Undefined";
    }
}

inline string Effect::getStringTarget (){
    return this->targetSelf ? "Self" : "Opponent";
}

inline string Effect::getStringStat (){
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

void Effect::display(int indexes[2]){
    cout << "\t";
    if (indexes[0] == 0)
        cout << ">";
    cout << "target :\t" + this->getStringTarget() + "\n";

    cout << "\t";
    if (indexes[0] == 1)
        cout << ">";
    cout << "stat :\t\t" + this->getStringStat() + "\n";

    cout << "\t";
    if (indexes[0] == 2)
        cout << ">";
    cout << "operation :\t" + this->getStringOperator() + "\n";

    cout << "\t";
    if (indexes[0] == 3)
        cout << ">";
    cout << "value :\t\t" + to_string(this->value) + "\n";
}

void Effect::setTarget (bool self){
    this->targetSelf = self;
}

void Effect::setTargetStat (int stat){
    this->targetStat = stat;
}

void Effect::setOperator (int operation){
    this->operation = operation;
}

void Effect::setValue (float value){
    this->value = value;
}
#pragma endregion getset
