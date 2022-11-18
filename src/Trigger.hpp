#ifndef TRIGGER__H
#define TRIGGER__H

#include <string>
#include <jsoncpp/json/json.h>

using namespace std;

class Trigger {
    // Attributes
  private:
    int stat;
    int threshold;

    // Operations
  public:
    Trigger ();
    Trigger (Json::Value val);
    /// returns all fields of the instance in a nicely formatted string for printing to console
    string getFormattedStats ();
    /// export the trigger as a JSON Value
    Json::Value jsonExport ();

    // Setters and Getters
    void setStat (int stat);
    void setThreshold (int threshold);

  private:
    inline string getStringStat ();
};
#endif
