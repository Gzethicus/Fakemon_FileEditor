#ifndef MOVE__H
#define MOVE__H

#include <string>
#include <jsoncpp/json/json.h>
#include "IPackageElement.hpp"

class Move : public IPackageElement {
  // Attributes
private:
  int power;
  /// type package and type name following the convention 'type_package/type_name'
  std::string type;
  int max;
  bool priority;
  /// effect package and effect name following the convention 'effect_package/effect_name'
  std::string effect;
  /// spritesheet and sprite name following the convention 'spritesheet/sprite_name'
  std::string sprite;
  // Operations
public:
  Move ();
  Move (Json::Value val);
  /// returns all fields of the instance in a nicely formatted string for printing to console
  std::string getFormattedStats ();

  /** Returns the move as a json value.
   *  @return A Json::Value representation of this instance.*/
  Json::Value jsonExport();

  // Displays the move to the console in a human-readable way.
  // @param indexes The selected path.
  void display(int indexes[2]);

    /** Sets an instance field.
        @param index The index of the field to edit.
        @param value A string representation of the new value.*/
    void setField(int indexes[2], string value);
    
    /** Execute the action to change the field designed by the given indexes
     *  @param indexes The indexes of the field to change.*/
    bool prompt(int indexes[2]);

  // Setters and Getters
  void setPower (int power);
  void setType (std::string type);
  void setMax (int max);
  void setPriority (bool priority);
  void setEffect (std::string effect);
  void setSprite (std::string sprite);
};
#endif
