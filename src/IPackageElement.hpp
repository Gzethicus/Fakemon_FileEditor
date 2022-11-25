#ifndef IPACKAGEELEMENT__H
#define IPACKAGEELEMENT__H

#include <sstream>
#include <ncurses.h>
#include <string>
#include <vector>
#include <jsoncpp/json/json.h>

using namespace std;

class IPackageElement {
    public:
        /** Returns the element as a json value.
         *  @return A Json::Value representation of this instance.*/
        virtual Json::Value jsonExport() = 0;

        /** Displays the element to the console in a human-readable way.
         *  @param indexes The selected path.
         *  @return A stringstream preformatted for printing to console.*/
        virtual stringstream display(int indexes[2]) = 0;

        /** Sets an instance field.
         *  @param indexes The indexes of the field to edit.
         *  @param value A string representation of the new value.*/
        virtual void setField(int indexes[2], string value) = 0;

        /** Execute the action to change the field designed by the given indexes.
         *  @param indexes The indexes of the field to change.
         *  @return `true` if a field has been modified, `false` if the explorer should go deeper.*/
        virtual bool prompt(int indexes[2]) = 0;
};
#endif
