#ifndef PACKAGE__H
#define PACKAGE__H

#include <string>
#include <unordered_map>
#include <vector>
#include <jsoncpp/json/json.h>

#include "Creature.hpp"
#include "Effect.hpp"
#include "Item.hpp"
#include "Move.hpp"
#include "Trigger.hpp"
#include "Type.hpp"

using namespace std;

class Package {
  // Attributes
private:
  int type;
  unordered_map<string, IPackageElement*> elements;
  vector<string> order;

  // Operations
public:
  /**Creates a new empty package of specified type
  @param type
    0 - Creature ||
    1 - Effect ||
    2 - Item ||
    3 - Move ||
    4 - Trigger ||
    5 - Type*/
  Package (int type);
  /**Creates a new package of specified type from the given json string
  @param type
    0 - Creature ||
    1 - Effect ||
    2 - Item ||
    3 - Move ||
    4 - Trigger ||
    5 - Type
    @param json A json representation of the package to build.*/
  Package (int type, string json);
  vector<string> getNames ();
  IPackageElement* get (string name);
  // Returns the package as a json value.
  // @return A Json::Value representation of this instance.
  Json::Value jsonExport ();
  void addElement (string name, IPackageElement* element);
  // Displays the package to the console in a human-readable way.
  // @param indexes The selected path.
  void display (int indexes[3]);
};
#endif