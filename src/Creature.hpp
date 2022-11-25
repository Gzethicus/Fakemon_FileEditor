#ifndef CREATURE__H
#define CREATURE__H

#include "IPackageElement.hpp"

#define NMOVES 4

using namespace std;

class Creature : public IPackageElement {
  private:
    int stats[4];
    string moves[NMOVES];
    string type;

  public:
    /** Instantiates a Creature with default stats, no moves and no type.*/
    Creature ();
    /** Instantiates a Creature corresponding to the given Json value.
     *  @param val A Json::Value that represents the Creature to be instanciated.*/
    Creature (Json::Value val);
    /** Returns the creature as a json value.
     *  @return A Json::Value representation of this instance.*/
    Json::Value jsonExport ();
    /** Displays the creature to the console in a human-readable way.
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

    void setStat (int stat, int value);
    void setMove (int id, string move);
    void setType (string type);
  
  private:
    inline void displayStats(int* index, stringstream& ss);
    inline void displayMoves(int* index, stringstream& ss);
};
#endif
