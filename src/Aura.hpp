#ifndef AURA__H
#define AURA__H

#include "IPackageElement.hpp"

using namespace std;

class Aura : public IPackageElement {
  private:
    int value;
    bool targetSelf;
    int targetStat;

  public:
    /** Instantiates an Aura with multiplier 0, on opponent's HP.*/
    Aura ();
    /** Instantiates an Aura corresponding to the given Json value.
     *  @param val A Json::Value that represents the Aura to be instanciated.*/
    Aura (Json::Value val);
    /** Returns the aura as a json value.
     *  @return A Json::Value representation of this instance.*/
    Json::Value jsonExport ();
    /** Displays the aura to the console in a human-readable way.
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

    /** Deletes the selected item if possible.
     *  @param indexes the tree to the selected item.*/
    void erase (int indexes[2]);

    void setValue (int value);
    void setTarget (bool self);
    void setTargetStat (int stat);

  private:
    inline string getStringTarget ();
    inline string getStringStat ();
};
#endif
