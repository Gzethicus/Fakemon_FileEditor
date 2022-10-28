#include "Effect.hpp"

using namespace std;

Effect::Effect() : operation{0}, value{0.f}, targetSelf{false} {
}

string Effect::getFormattedStats (){
    string formatted = "\toperation :\t" + this->getStringOperator() + "\n";
    formatted += "\tvalue :\t\t" + to_string(this->value) + "\n";
    formatted += "\ttarget :\t" + to_string(this->targetSelf) + "\n";
    return formatted;
}

string Effect::jsonExport (){
    string json = "{\"operation\":" + to_string(this->operation) + ",\"value\":" + to_string(this->value) + ",\"targetSelf\":" + to_string(this->targetSelf) + "}";
    return json;
}

#pragma region getset
string Effect::getStringOperator (){
    string operation;
    switch (this->operation){
        case 0:
            operation = "add";
            break;
        case 1:
            operation = "mult";
            break;
        default:
            operation = "undefined";
            break;
    }
    return operation;
}

void Effect::setOperator (int operation){
    this->operation = operation;
}

void Effect::setValue (float value){
    this->value = value;
}

void Effect::setTarget (bool self){
    this->targetSelf = self;
}
#pragma endregion getset
