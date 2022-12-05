#ifndef PACKAGE__H
#define PACKAGE__H

#include <string>
#include <unordered_map>
#include <set>
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
  set<string> order;

  // Operations
public:
  /** Creates a new empty package of specified type
   *  @param type
   *  0 - Creature ||
   *  1 - Effect ||
   *  2 - Item ||
   *  3 - Move ||
   *  4 - Trigger ||
   *  5 - Type*/
  Package (int type);

  /** Creates a new package of specified type from the given json string
   *  @param json A json representation of the package to build.*/
  Package (string json);

  set<string> getNames ();
  IPackageElement* get (string name);
  /** Returns the package as a json value.
   *  @return A Json::Value representation of this instance.*/
  Json::Value jsonExport ();

  /** Adds an element to this package.
   *  @param name The unique identifier for the element.
   *  @param element A pointer to the element to be added to the package.s*/
  void addElement (string name, IPackageElement* element);

  /** Adds an element to this package.
   *  @param name The unique identifier for the element.*/
  void addNew (string name);
  
  /** Returns the package in a human-readable stringstream.
   *  @param indexes The selected path.
   *  @param ss A stringstream to append content to, preformatted for printing to console.*/
  void display (int indexes[3], stringstream& ss);

  /** Attempts to change selected item, potentially prompting from CLI.
   *  @param indexes the tree to the selected item.
   *  @return `true` if a field has been modified, `false` if the explorer should go deeper.*/
  bool prompt (int indexes[3]);

  /** Deletes the selected item.
   *  @param indexes the tree to the selected item.*/
  void erase (int indexes[3]);
};
#endif
