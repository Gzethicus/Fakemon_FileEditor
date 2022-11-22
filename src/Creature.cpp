#include "Creature.hpp"

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

void Creature::display(int indexes[2]){
    cout << "\t";
    if (indexes[0] == 0)
        cout << ">";
    cout << "stat :\n";
    this->displayStats(indexes[0] == 0 ? &(indexes[1]) : (int*) -1);

    cout << "\t";
    if (indexes[0] == 1)
        cout << ">";
    cout << "moves :\n";
    this->displayMoves(indexes[0] == 1 ? &(indexes[1]) : (int*) -1);

    cout << "\t";
    if (indexes[0] == 2)
        cout << ">";
    cout << "type :\t" << (this->type.empty() ? "undefined !" : this->type) << endl;
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

void Creature::displayStats(int index[1]){
    cout << "\t\t";
    if (index[0] == 0)
        cout << ">";
    cout << "HP :\t" << to_string(this->stats[0]) << endl;

    cout << "\t\t";
    if (index[0] == 1)
        cout << ">";
    cout << "ATK :\t" << to_string(this->stats[1]) << endl;

    cout << "\t\t";
    if (index[0] == 2)
        cout << ">";
    cout << "DEF :\t" << to_string(this->stats[2]) << endl;

    cout << "\t\t";
    if (index[0] == 3)
        cout << ">";
    cout << "SPD :\t" << to_string(this->stats[3]) << endl;
}

void Creature::displayMoves(int index[1]){
    for (int i = 0; i < NMOVES; i++){
        cout << "\t\t";
        if (i == index[0])
            cout << ">";
        cout << (this->moves[i].empty() ? "undefined !" : this->moves[i]) << endl;
    }
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
