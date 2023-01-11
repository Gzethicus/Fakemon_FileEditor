#include "Move.hpp"

using namespace std;

Move::Move () : power{0}, type{""}, max{1}, priority{false}, aura{""}, sprite{""}{}

Move::Move (Json::Value val){
    this->power = val["power"].asInt();
    this->type = val["type"].asString();
    this->max = val["max"].asInt();
    this->priority = val["priority"].asBool();
    this->aura = val["aura"].asString();
    this->sprite = val["sprite"].asString();
}

Json::Value Move::jsonExport ( ){
    Json::Value json;
    json["power"] = this->power;
    json["type"] = this->type;
    json["max"] = this->max;
    json["priority"] = this->priority;
    json["aura"] = this->aura;
    json["sprite"] = this->sprite;
    return json;
}

void Move::display(int indexes[2], stringstream& ss){
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
    ss << "aura :\t\t" << (this->aura.empty() ? "none" : this->aura) << "\n";

    ss << "\t";
    if (indexes[0] == 5)
        ss << ">";
    ss << "sprite :\t" << (this->sprite.empty() ? "none" : this->sprite) << "\n";
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
            this->aura = value;
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
        printw(">");
        char* val = (char*)calloc(32, sizeof(char));
        getstr(val);
        this->setField(indexes, val);
        free(val);
    }
    return true;
}

void Move::erase(int indexes[2]) {

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
void Move::setAura (std::string aura){
    this->aura = aura;
}
void Move::setSprite (std::string sprite){
    this->sprite = sprite;
}
