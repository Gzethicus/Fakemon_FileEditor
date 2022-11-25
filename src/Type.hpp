#ifndef TYPE__H
#define TYPE__H

#include <string>
#include <unordered_map>
#include <jsoncpp/json/json.h>

#include "IPackageElement.hpp"

using namespace std;

class Type : public IPackageElement {
    // Attributes
  private:
    unordered_map<string, float> factors;
    vector<string> order;

    // Operations
  public:
    Type ();
    Type (Json::Value val);
    // returns all fields of the instance in a nicely formatted string for printing to console
    string getFormattedStats ();

    /** Returns the type as a json value.
     *  @return A Json::Value representation of this instance.*/
    Json::Value jsonExport();

    /** Displays the type to the console in a human-readable way.
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
    void setFactor (string type, float factor);
};
#endif
