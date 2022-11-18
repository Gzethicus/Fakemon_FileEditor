#ifndef MOVEPACKAGE__H
#define MOVEPACKAGE__H

#include <string>
#include <unordered_map>
#include <vector>
#include <jsoncpp/json/json.h>

#include "Move.hpp"
#include "IPackage.hpp"

using namespace std;

class MovePackage : public IPackage{
  // Attributes
private:
  unordered_map<std::string, Move> moves;
  vector<string> typeDependencies;
  vector<string> spriteDependencies;
  vector<string> effectDependencies;
  // Operations
public:
MovePackage();
MovePackage(string json);
  vector<string> getNames ();
  Move* get (string name);
  /// exports the package as a JSON Value
  Json::Value jsonExport ( );
  void addMove (std::string name, Move move);
  // Setters and Getters
};
#endif
