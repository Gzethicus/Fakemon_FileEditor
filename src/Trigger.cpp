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

void Trigger::display(int indexes[2], stringstream& ss){
    if (indexes[0] > 1)
        indexes[0] = 1;
    ss << "\t";
    if (indexes[0] == 0)
        ss << ">";
    ss << "stat :\t\t" << this->getStringStat() << "\n";

    ss << "\t";
    if (indexes[0] == 1)
        ss << ">";
    ss << "threshold :\t" << to_string(this->threshold) << "\n";
}

void Trigger::setField(int indexes[2], string value){
    switch (indexes[0]){
        case 0:
            this->stat = stoi(value);
            break;
        case 1:
            this->threshold = stoi(value);
            break;
    }
}

bool Trigger::prompt(int indexes[2]){
    if (indexes[0] == 0)
        this->stat = (this->stat + 1) % 4;
    else{
        printw(">");
        char* val = (char*)calloc(32, sizeof(char));
        getstr(val);
        setField(indexes, val);
        free(val);
    }
    return true;
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
