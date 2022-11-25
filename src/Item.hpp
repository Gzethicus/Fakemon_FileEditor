#ifndef ITEM__H
#define ITEM__H

#include <string>
#include <jsoncpp/json/json.h>

#include "IPackageElement.hpp"
#include "Trigger.hpp"
#include "Effect.hpp"

using namespace std;

class Item : public IPackageElement {
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
    /** Returns the item as a json value.
     *  @return A Json::Value representation of this instance.*/
    Json::Value jsonExport();
    /** Displays the item to the console in a human-readable way.
     *  @param indexes The selected path.
     *  @return A stringstream preformatted for printing to console.*/
    stringstream display(int indexes[2]);
    /** Sets an instance field.
     *  @param index The index of the field to edit.
     *  @param value A string representation of the new value.*/
    void setField(int indexes[2], string value);
    
    /** Execute the action to change the field designed by the given indexes
     *  @param indexes The indexes of the field to change.
     *  @return `true` if a field has been modified, `false` if the explorer should go deeper.*/
    bool prompt(int indexes[2]);

    // Setters and Getters
    void setTrigger (string trigger);
    void setEffect (string effect);
};
#endif
