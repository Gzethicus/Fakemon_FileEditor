#ifndef EFFECTPACKAGE__H
#define EFFECTPACKAGE__H

#include <string>
#include <unordered_map>
#include <vector>

#include "Move.hpp"
#include "Effect.hpp"
#include "Package.hpp"

using namespace std;

class EffectPackage : public Package{
  // Attributes
private:
  unordered_map<string, Effect> effects;

  // Operations
public:
  vector<string> getNames ();
  Move get (string name);
  /// exports the package as a JSON string
  string jsonExport ();
  void addEffect (string name, Effect effect);
};
#endif
