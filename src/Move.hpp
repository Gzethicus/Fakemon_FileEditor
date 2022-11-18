#ifndef MOVE__H
#define MOVE__H

#include <string>
#include <jsoncpp/json/json.h>

class Move {
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
  /// exports the move as a JSON string
  Json::Value jsonExport ( );
  // Setters and Getters
  void setPower (int power);
  void setType (std::string type);
  void setMax (int max);
  void setPriority (bool priority);
  void setEffect (std::string effect);
  void setSprite (std::string sprite);
};
#endif
