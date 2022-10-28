#ifndef EFFECT__H
#define EFFECT__H

#include <string>

using namespace std;

class Effect {
    // Attributes
  private:
    int operation;
    float value;
    bool targetSelf;

    // Operations
  public:
    Effect ();
    /// returns all fields of the instance in a nicely formatted string for printing to console
    string getFormattedStats ();
    /// export the effect as a JSON string
    string jsonExport ();

    // Setters and Getters
    void setOperator (int operation);
    void setValue (float value);
    void setTarget (bool self);

  private:
    string getStringOperator ();
};
#endif
