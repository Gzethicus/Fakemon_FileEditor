#ifndef TYPEPACKAGE__H
#define TYPEPACKAGE__H

#include <string>
#include <unordered_map>
#include <vector>
#include <jsoncpp/json/json.h>

#include "Type.hpp"
#include "IPackage.hpp"

using namespace std;

class TypePackage : public IPackage{
  // Attributes
private:
  unordered_map<string, Type> types;

  // Operations
public:
  TypePackage ();
  TypePackage (string json);
  vector<string> getNames ();
  Type* get (string name);
  /// exports the package as a JSON value
  Json::Value jsonExport ();
  void addType (string name, Type type);
};
#endif
