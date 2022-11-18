#ifndef ITEM__H
#define ITEM__H

#include <string>
#include <jsoncpp/json/json.h>

#include "Trigger.hpp"
#include "Effect.hpp"

using namespace std;

class Item {
    // Attributes
  private:
    string trigger;
    string effect;

    // Operations
  public:
    Item ();
    Item (Json::Value val);
    /// returns all fields of the instance in a nicely formatted string for printing to console
    string getFormattedStats ();
    /// export the effect as a JSON Value
    Json::Value jsonExport ();

    // Setters and Getters
    void setTrigger (string trigger);
    void setEffect (string effect);
};
#endif
