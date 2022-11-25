#ifndef TRIGGER__H
#define TRIGGER__H

#include <string>
#include <jsoncpp/json/json.h>

#include "IPackageElement.hpp"

using namespace std;

class Trigger : public IPackageElement{
    // Attributes
  private:
    int stat;
    int threshold;

    // Operations
  public:
    /** Instantiates a Trigger on 100% HP.*/
    Trigger ();
    /** Instantiates a Trigger corresponding to the given Json value.
     *  @param val A Json::Value that represents the Trigger to be instanciated.*/
    Trigger (Json::Value val);

    /** Returns the trigger as a json value.
     *  @return A Json::Value representation of this instance.*/
    Json::Value jsonExport();

    /** Displays the trigger to the console in a human-readable way.
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

    /** Sets the stat on which effects will be triggered.
     *  @param stat 0 - HP ||
     *  1 - ATK ||
     *  2 - DEF ||
     *  3 - SPD*/
    void setStat (int stat);

    /** Sets the threshold on which the effect will be triggered.
     *  @param threshold Percentage value (0-100, or more for triggers on increased stat)*/
    void setThreshold (int threshold);

  private:
    inline string getStringStat ();
};
#endif
