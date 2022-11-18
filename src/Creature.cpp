#include "Creature.hpp"
#include <iostream>

using namespace std;

Creature::Creature() : stats{{100}}, moves{{""}}, type{""}{}

Creature::Creature (Json::Value val){
    for (int i = 0; i < 4; i++)
        this->stats[i] = val["stats"][i].asInt();

    for (int i = 0; i < NMOVES; i++)
        this->moves[i] = val["moves"][i].asString();
    
    this->type = val["type"].asString();
}

string Creature::getFormattedStats (){
    string formatted = "\tstats :\n";
    formatted += "\t\tHP :\t" + to_string(this->stats[0]) + "\n";
    formatted += "\t\tATK :\t" + to_string(this->stats[1]) + "\n";
    formatted += "\t\tDEF :\t" + to_string(this->stats[2]) + "\n";
    formatted += "\t\tSPD :\t" + to_string(this->stats[3]) + "\n";
    formatted += "\tmoves :\n";
    for (int i = 0; i < NMOVES; i++)
        formatted += "\t\t" + (this->moves[i].empty() ? "undefined !" : this->moves[i]) + "\n";
    formatted += "\ttype :\t" + (this->type.empty() ? "undefined !" : this->type) + "\n";
    return formatted;
}

Json::Value Creature::jsonExport (){
    Json::Value json;
    Json::Value stats;
    for (int i = 0; i < 4; i++)
        stats.append(this->stats[i]);
    json["stats"] = stats;
    Json::Value moves;
    for (int i = 0; i < NMOVES; i++)
        moves.append(this->moves[i]);
    json["moves"] = moves;
    json["type"] = this->type;
    return json;
}

#pragma region getset
void Creature::setStat (int stat, int value){
    this->stats[stat] = value;
}

void Creature::setMove (int id, string move){
    this->moves[id] = move;
}

void Creature::setType (string type){
    this->type = type;
}
#pragma endregion getset
