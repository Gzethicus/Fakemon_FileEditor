#include "Move.hpp"

using namespace std;

Move::Move () : power{0}, type{""}, max{0}, priority{false}, effect{""}, sprite{""}{}

Move::Move (Json::Value val){
    this->power = val["power"].asInt();
    this->type = val["type"].asString();
    this->max = val["max"].asInt();
    this->priority = val["priority"].asBool();
    this->effect = val["effect"].asString();
    this->sprite = val["sprite"].asString();
}

std::string Move::getFormattedStats (){
    string formatted = "\tpower :\t\t" + to_string(this->power) + "\n";
    formatted += "\ttype :\t\t" + (this->type.empty() ? "neutral" : this->type) + "\n";
    formatted += "\tmax :\t\t" + to_string(this->max) + "\n";
    formatted += "\thasPriority :\t" + to_string(this->priority) + "\n";
    formatted += "\teffect :\t" + (this->effect.empty() ? "none" : this->effect) + "\n";
    formatted += "\tsprite :\t" + (this->sprite.empty() ? "none" : this->sprite) + "\n";
    return formatted;
}

Json::Value Move::jsonExport ( ){
    Json::Value json;
    json["power"] = this->power;
    json["type"] = this->type;
    json["max"] = this->max;
    json["priority"] = this->priority;
    json["effect"] = this->effect;
    json["sprite"] = this->sprite;
    return json;
}

stringstream Move::display(int indexes[2]){
    stringstream ss;
    if (indexes[0] > 5)
        indexes[0] = 5;
    ss << "\t";
    if (indexes[0] == 0)
        ss << ">";
    ss << "power :\t\t" << to_string(this->power) << "\n";

    ss << "\t";
    if (indexes[0] == 1)
        ss << ">";
    ss << "type :\t\t" << (this->type.empty() ? "neutral" : this->type) << "\n";

    ss << "\t";
    if (indexes[0] == 2)
        ss << ">";
    ss << "max :\t\t" << to_string(this->max) << "\n";

    ss << "\t";
    if (indexes[0] == 3)
        ss << ">";
    ss << "hasPriority :\t" << to_string(this->priority) << "\n";

    ss << "\t";
    if (indexes[0] == 4)
        ss << ">";
    ss << "effect :\t" << (this->effect.empty() ? "none" : this->effect) << "\n";

    ss << "\t";
    if (indexes[0] == 5)
        ss << ">";
    ss << "sprite :\t" << (this->sprite.empty() ? "none" : this->sprite) << "\n";
    return ss;
}

void Move::setField(int indexes[2], string value){
    switch (indexes[0]){
        case 0:
            this->power = stoi(value);
            break;
        case 1:
            this->type = value;
            break;
        case 2:
            this->max = stoi(value);
            break;
        case 3:
            this->priority = !value.empty();
            break;
        case 4:
            this->effect = value;
            break;
        case 5:
            this->sprite = value;
            break;
    }
}

bool Move::prompt(int indexes[2]){
    if (indexes[0] == 3)
        this->priority ^= true;
    else{
        char* val = (char*)calloc(32, sizeof(char));
        getstr(val);
        this->setField(indexes, val);
        free(val);
    }
    return true;
}

void Move::setPower (int power){
    this->power = power;
}
void Move::setType (std::string type){
    this->type = type;
}
void Move::setMax (int max){
    this->max = max;
}
void Move::setPriority (bool priority){
    this->priority = priority;
}
void Move::setEffect (std::string effect){
    this->effect = effect;
}
void Move::setSprite (std::string sprite){
    this->sprite = sprite;
}
