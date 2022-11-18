#include "MovePackage.hpp"
#include <memory>

using namespace std;

MovePackage::MovePackage () : moves{unordered_map<string, Move>()}{}

MovePackage::MovePackage (string json) {
    Json::CharReaderBuilder builder;
    unique_ptr<Json::CharReader> reader = unique_ptr<Json::CharReader> (builder.newCharReader());
    Json::Value val {};
    string err {};
    this->moves = unordered_map<string, Move>();

    reader->parse(json.c_str(), json.c_str() + json.length(), &val, &err);
    this->moves.reserve(val.size());

    for (Json::ValueIterator move = val.begin(); move != val.end(); move++){
        this->moves[move.name()] = Move(val[move.name()]);
    }
}

vector<string> MovePackage::getNames () {
    vector<string> keys;
    keys.reserve(this->moves.size());

    for(auto key : this->moves)
        keys.push_back(key.first);
    
    return keys;
}

Move* MovePackage::get (string name){
    return &(this->moves[name]);
}

Json::Value MovePackage::jsonExport (){
    Json::Value package;

    for(auto key : this->moves)
        package[key.first] = key.second.jsonExport();
    
    return package;
}

void MovePackage::addMove (string name, Move move){
    this->moves[name] = move;
}
