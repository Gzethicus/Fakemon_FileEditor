#include "Item.hpp"

using namespace std;

Item::Item() : trigger{""}, effect{""}{}

Item::Item (Json::Value val){
    this->trigger = val["trigger"].asString();
    this->effect = val["effect"].asString();
}

Json::Value Item::jsonExport (){
    Json::Value json;
    json["trigger"] = this->trigger;
    json["effect"] = this->effect;
    return json;
}

void Item::display (int indexes[2], stringstream& ss){
    if (indexes[0] > 1)
        indexes[0] = 1;
    ss << "\t";
    if (indexes[0] == 0)
        ss << ">";
    ss << "trigger :\t" << (this->trigger.empty() ? "undefined !" : this->trigger) << "\n";

    ss << "\t";
    if (indexes[0] == 1)
        ss << ">";
    ss << "effect :\t" << (this->effect.empty() ? "undefined !" : this->effect) << "\n";
}

void Item::setField(int indexes[2], string value){
    switch (indexes[0]){
        case 0:
            this->trigger = value;
            break;
        case 1:
            this->effect = value;
            break;
    }
}

bool Item::prompt(int indexes[2]){
    printw(">");
    char* val = (char*)calloc(32, sizeof(char));
    getstr(val);
    this->setField(indexes, val);
    free(val);
    return true;
}

void Item::erase(int indexes[2]) {

}

#pragma region getset
void Item::setTrigger (string trigger){
    this->trigger = trigger;
}

void Item::setEffect (string effect){
    this->effect = effect;
}
#pragma endregion getset
