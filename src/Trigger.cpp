#include "Trigger.hpp"

using namespace std;

Trigger::Trigger() : stat{0}, threshold{100} {}

Trigger::Trigger (Json::Value val){
    this->stat = val["stat"].asInt();
    this->threshold = val["threshold"].asInt();
}

string Trigger::getFormattedStats (){
    string formatted = "\tstat :\t\t" + this->getStringStat() + "\n";
    formatted += "\tthreshold :\t" + to_string(this->threshold) + "%\n";
    return formatted;
}

Json::Value Trigger::jsonExport (){
    Json::Value json;
    json["stat"] = this->stat;
    json["threshold"] = this->threshold;
    return json;
}

#pragma region getset
inline string Trigger::getStringStat (){
    switch (this->stat){
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

void Trigger::setStat (int stat){
    this->stat = stat;
}

void Trigger::setThreshold (int threshold){
    this->threshold = threshold;
}
#pragma endregion getset
