#ifndef ITEM__H
#define ITEM__H

#include <string>
#include <jsoncpp/json/json.h>

#include "IPackageElement.hpp"
#include "Trigger.hpp"
#include "Effect.hpp"

using namespace std;

class Item : public IPackageElement {
  private:
    string trigger;
    string effect;

  public:
    /** Instantiates an Item with no trigger and no effect.*/
    Item ();
    /** Instantiates an Item corresponding to the given Json value.
     *  @param val A Json::Value that represents the Item to be instanciated.*/
    Item (Json::Value val);
    /** Returns the item as a json value.
     *  @return A Json::Value representation of this instance.*/
    Json::Value jsonExport();
    /** Displays the item to the console in a human-readable way.
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

    void setTrigger (string trigger);
    void setEffect (string effect);
};
#endif
