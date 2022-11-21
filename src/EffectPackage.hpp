#ifndef EFFECTPACKAGE__H
#define EFFECTPACKAGE__H

#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <jsoncpp/json/json.h>

#include "Effect.hpp"
#include "IPackage.hpp"

using namespace std;

class EffectPackage : public IPackage{
  // Attributes
private:
  unordered_map<string, Effect> effects;
  vector<string> order;

  // Operations
public:
  EffectPackage ();
  EffectPackage (string json);
  vector<string> getNames ();
  Effect* get (string name);
  /// exports the package as a JSON value
  Json::Value jsonExport ();
  void addEffect (string name, Effect effect);
  void display (int indexes[3]);
};
#endif
