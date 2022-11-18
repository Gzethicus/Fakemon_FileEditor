#ifndef TYPE__H
#define TYPE__H

#include <string>
#include <unordered_map>
#include <jsoncpp/json/json.h>

using namespace std;

class Type {
    // Attributes
  private:
    unordered_map<string, float> factors;

    // Operations
  public:
    Type ();
    Type (Json::Value val);
    /// returns all fields of the instance in a nicely formatted string for printing to console
    string getFormattedStats ();
    /// export the type as a JSON Value
    Json::Value jsonExport ();

    // Setters and Getters
    void setFactor (string type, float factor);
};
#endif
