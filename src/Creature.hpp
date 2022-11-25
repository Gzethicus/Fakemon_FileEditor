#ifndef CREATURE__H
#define CREATURE__H

#include "IPackageElement.hpp"

#define NMOVES 4

using namespace std;

class Creature : public IPackageElement {
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
    /** Returns the creature as a json value.
     *  @return A Json::Value representation of this instance.*/
    Json::Value jsonExport ();
    /** Displays the creature to the console in a human-readable way.
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
    void setStat (int stat, int value);
    void setMove (int id, string move);
    void setType (string type);
  
  private:
    inline void displayStats(int* index);
    inline void displayMoves(int* index);
};
#endif
