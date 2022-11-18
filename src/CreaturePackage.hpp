#ifndef CREATUREPACKAGE__H
#define CREATUREPACKAGE__H

#include <string>
#include <unordered_map>
#include <vector>
#include <jsoncpp/json/json.h>

#include "Creature.hpp"
#include "IPackage.hpp"

using namespace std;

class CreaturePackage : public IPackage{
  // Attributes
private:
  unordered_map<string, Creature> creatures;

  // Operations
public:
  CreaturePackage ();
  CreaturePackage (string json);
  vector<string> getNames ();
  Creature* get (string name);
  /// exports the package as a JSON value
  Json::Value jsonExport ();
  void addCreature (string name, Creature creature);
};
#endif
