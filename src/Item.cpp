#include "Item.hpp"

using namespace std;

Item::Item() : trigger{""}, effect{""}{}

Item::Item (Json::Value val){
    this->trigger = val["trigger"].asString();
    this->effect = val["effect"].asString();
}

string Item::getFormattedStats (){
    string formatted = "\ttrigger :\t" + (this->trigger.empty() ? "undefined !" : this->trigger) + "\n";
    formatted += "\teffect :\t" + (this->effect.empty() ? "undefined !" : this->effect) + "\n";
    return formatted;
}

Json::Value Item::jsonExport (){
    Json::Value json;
    json["trigger"] = this->trigger;
    json["effect"] = this->effect;
    return json;
}

void Item::display (int indexes[2]){
    cout << "\t";
    if (indexes[0] == 0)
        cout << ">";
    cout << "trigger :\t" << (this->trigger.empty() ? "undefined !" : this->trigger) << endl;

    cout << "\t";
    if (indexes[0] == 1)
        cout << ">";
    cout << "effect :\t" << (this->effect.empty() ? "undefined !" : this->effect) << endl;
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

#pragma region getset
void Item::setTrigger (string trigger){
    this->trigger = trigger;
}

void Item::setEffect (string effect){
    this->effect = effect;
}
#pragma endregion getset
