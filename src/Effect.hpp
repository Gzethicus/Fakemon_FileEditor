#ifndef EFFECT__H
#define EFFECT__H

#include <string>
#include <jsoncpp/json/json.h>

using namespace std;

class Effect {
    // Attributes
  private:
    int operation;
    float value;
    bool targetSelf;
    int targetStat;

    // Operations
  public:
    Effect ();
    Effect (Json::Value val);
    /// returns all fields of the instance in a nicely formatted string for printing to console
    string getFormattedStats ();
    /// export the effect as a JSON Value
    Json::Value jsonExport ();
    void display(int indexes[2]);

    // Setters and Getters
    void setOperator (int operation);
    void setValue (float value);
    void setTarget (bool self);
    void setTargetStat (int stat);

  private:
    inline string getStringOperator ();
    inline string getStringTarget ();
    inline string getStringStat ();
};
#endif
