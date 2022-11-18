#ifndef TRIGGERPACKAGE__H
#define TRIGGERPACKAGE__H

#include <string>
#include <unordered_map>
#include <vector>
#include <jsoncpp/json/json.h>

#include "Trigger.hpp"
#include "IPackage.hpp"

using namespace std;

class TriggerPackage : public IPackage{
  // Attributes
private:
  unordered_map<string, Trigger> triggers;

  // Operations
public:
  TriggerPackage ();
  TriggerPackage (string json);
  vector<string> getNames ();
  Trigger* get (string name);
  /// exports the package as a JSON value
  Json::Value jsonExport ();
  void addTrigger (string name, Trigger trigger);
};
#endif
