#ifndef ITEMPACKAGE__H
#define ITEMPACKAGE__H

#include <string>
#include <unordered_map>
#include <vector>
#include <jsoncpp/json/json.h>

#include "Item.hpp"
#include "IPackage.hpp"

using namespace std;

class ItemPackage : public IPackage{
  // Attributes
private:
  unordered_map<string, Item> items;

  // Operations
public:
  ItemPackage ();
  ItemPackage (string json);
  vector<string> getNames ();
  Item* get (string name);
  /// exports the package as a JSON value
  Json::Value jsonExport ();
  void addItem (string name, Item item);
};
#endif
