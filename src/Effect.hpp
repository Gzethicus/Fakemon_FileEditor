#ifndef EFFECT__H
#define EFFECT__H

#include <string>
#include <jsoncpp/json/json.h>

#include "IPackageElement.hpp"

using namespace std;

class Effect : public IPackageElement {
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
    // Returns the effect as a json value.
    // @return A Json::Value representation of this instance.
    Json::Value jsonExport ();
    // Displays the effect to the console in a human-readable way.
    // @param indexes The selected path.
    void display(int indexes[2]);
    /** Sets an instance field.
        @param index The index of the field to edit.
        @param value A string representation of the new value.*/
    void setField(int index, string value);

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
