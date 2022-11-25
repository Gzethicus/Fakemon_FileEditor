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
    /** Returns the effect as a json value.
     *  @return A Json::Value representation of this instance.*/
    Json::Value jsonExport ();
    /** Displays the effect to the console in a human-readable way.
     *  @param indexes The selected path.
     *  @param ss A stringstream to append content to, preformatted for printing to console.*/
    void display(int indexes[2], stringstream& ss);
    /** Sets an instance field.
     *  @param index The index of the field to edit.
     *  @param value A string representation of the new value.*/
    void setField(int indexes[2], string value);

    /** Execute the action to change the field designed by the given indexes
     *  @param indexes The indexes of the field to change.
     *  @return `true` if a field has been modified, `false` if the explorer should go deeper.*/
    bool prompt(int indexes[2]);

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
