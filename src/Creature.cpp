#include "Creature.hpp"

using namespace std;

Creature::Creature() : stats{100, 100, 100, 100}, moves{""}, type{""}{}

Creature::Creature (Json::Value val){
    for (int i = 0; i < 4; i++)
        this->stats[i] = val["stats"][i].asInt();

    for (int i = 0; i < NMOVES; i++)
        this->moves[i] = val["moves"][i].asString();
    
    this->type = val["type"].asString();
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

void Creature::display(int indexes[2], stringstream& ss){
    if (indexes[0] > 2)
        indexes[0] = 2;
    if (indexes[1] > 3)
        indexes[1] = 3;
    ss << "\t";
    if (indexes[0] == 0)
        ss << ">";
    ss << "stat :\n";
    this->displayStats(indexes[0] == 0 ? &(indexes[1]) : new int(-1), ss);

    ss << "\t";
    if (indexes[0] == 1)
        ss << ">";
    ss << "moves :\n";
    this->displayMoves(indexes[0] == 1 ? &(indexes[1]) : new int(-1), ss);

    ss << "\t";
    if (indexes[0] == 2)
        ss << ">";
    ss << "type :\t" << (this->type.empty() ? "undefined !" : this->type) << "\n";
}

void Creature::setField(int indexes[2], string value){
    switch (indexes[0]){
        case 0:
            this->stats[indexes[1]] = stoi(value);
            break;
        case 1:
            this->moves[indexes[1]] = value;
            break;
        case 2:
            this->type = value;
            break;
    }
}

bool Creature::prompt(int indexes[2]){
    if (indexes[0] < 2 && indexes[1] == -1)
        return false;
    printw(">");
    char* val = (char*)calloc(32, sizeof(char));
    getstr(val);
    this->setField(indexes, val);
    free(val);
    return true;
}

void Creature::displayStats(int index[1], stringstream& ss){
    ss << "\t\t";
    if (index[0] == 0)
        ss << ">";
    ss << "HP :\t" << to_string(this->stats[0]) << "\n\t\t";

    if (index[0] == 1)
        ss << ">";
    ss << "ATK :\t" << to_string(this->stats[1]) << "\n\t\t";

    if (index[0] == 2)
        ss << ">";
    ss << "DEF :\t" << to_string(this->stats[2]) << "\n\t\t";

    if (index[0] == 3)
        ss << ">";
    ss << "SPD :\t" << to_string(this->stats[3]) << "\n";
}

void Creature::displayMoves(int index[1], stringstream& ss){
    for (int i = 0; i < NMOVES; i++){
        ss << "\t\t";
        if (i == index[0])
            ss << ">";
        ss << (this->moves[i].empty() ? "undefined !" : this->moves[i]) << "\n";
    }
}

void Creature::erase(int indexes[2]) {

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
