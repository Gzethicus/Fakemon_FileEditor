#ifndef EFFECTPACKAGE__H
#define EFFECTPACKAGE__H

#include <string>
#include <unordered_map>
#include <vector>

#include "Move.hpp"
#include "Effect.hpp"
#include "IPackage.hpp"

using namespace std;

class EffectPackage : public IPackage{
  // Attributes
private:
  unordered_map<string, Effect> effects;

  // Operations
public:
  vector<string> getNames ();
  Effect get (string name);
  /// exports the package as a JSON string
  string jsonExport ();
  void addEffect (string name, Effect effect);
};
#endif
