#ifndef MOVE__H
#define MOVE__H

#include "IPackageElement.hpp"

using namespace std;

class Move : public IPackageElement {
  private:
    int power;
    string type;
    int max;
    bool priority;
    string aura;
    string sprite;
  public:
    /** Instantiates a Move with no power, no type, one max charge, no priority, no aura and no sprite.*/
    Move ();
    /** Instantiates a Move corresponding to the given Json value.
     *  @param val A Json::Value that represents the Move to be instanciated.*/
    Move (Json::Value val);

    /** Returns the move as a json value.
     *  @return A Json::Value representation of this instance.*/
    Json::Value jsonExport();

    /** Displays the move to the console in a human-readable way.
     *  @param indexes The selected path.
     *  @param ss A stringstream to append content to, preformatted for printing to console.*/
    void display(int indexes[2], stringstream& ss);

    /** Sets an instance field.
        @param index The index of the field to edit.
        @param value A string representation of the new value.*/
    void setField(int indexes[2], string value);
      
    /** Execute the action to change the field designed by the given indexes
     *  @param indexes The indexes of the field to change.
     *  @return `true` if a field has been modified, `false` if the explorer should go deeper.*/
    bool prompt(int indexes[2]);

    /** Deletes the selected item if possible.
     *  @param indexes the tree to the selected item.*/
    void erase (int indexes[2]);

    void setPower (int power);
    void setType (string type);
    void setMax (int max);
    void setPriority (bool priority);
    void setAura (string aura);
    void setSprite (string sprite);
};
#endif
