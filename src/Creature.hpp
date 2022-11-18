#ifndef CREATURE__H
#define CREATURE__H

#include <string>
#include <jsoncpp/json/json.h>

#define NMOVES 4

using namespace std;

class Creature {
    // Attributes
  private:
    int stats[4];
    string moves[NMOVES];
    string type;

    // Operations
  public:
    Creature ();
    Creature (Json::Value val);
    /// returns all fields of the instance in a nicely formatted string for printing to console
    string getFormattedStats ();
    /// export the creature as a JSON Value
    Json::Value jsonExport ();

    // Setters and Getters
    void setStat (int stat, int value);
    void setMove (int id, string move);
    void setType (string type);
};
#endif
