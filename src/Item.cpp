#include "Item.hpp"

using namespace std;

Item::Item() : trigger{""}, aura{""}{}

Item::Item (Json::Value val){
    this->trigger = val["trigger"].asString();
    this->aura = val["aura"].asString();
}

Json::Value Item::jsonExport (){
    Json::Value json;
    json["trigger"] = this->trigger;
    json["aura"] = this->aura;
    return json;
}

void Item::display (int indexes[2], stringstream& ss){
    if (indexes[0] > 1)
        indexes[0] = 1;
    ss << "\t";
    if (indexes[0] == 0)
        ss << ">";
    ss << "trigger :\t" << (this->trigger.empty() ? "permanent" : this->trigger) << "\n";

    ss << "\t";
    if (indexes[0] == 1)
        ss << ">";
    ss << "aura :\t\t" << (this->aura.empty() ? "undefined !" : this->aura) << "\n";
}

void Item::setField(int indexes[2], string value){
    switch (indexes[0]){
        case 0:
            this->trigger = value;
            break;
        case 1:
            this->aura = value;
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

void Item::setAura (string aura){
    this->aura = aura;
}
#pragma endregion getset
