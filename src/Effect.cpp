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
string Effect::getStringOperator (){
    switch (this->operation){
        case 0:
            return "add";
        case 1:
            return "mult";
        default:
            return "undefined";
    }
}

string Effect::getStringTarget (){
    switch (this->targetSelf){
        case true:
            return "self";
        case false:
            return "opponent";
    }
}

string Effect::getStringStat (){
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
            return "undefined";
    }
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
