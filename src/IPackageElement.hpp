#ifndef IPACKAGEELEMENT__H
#define IPACKAGEELEMENT__H

#include <iostream>
#include <string>
#include <vector>
#include <jsoncpp/json/json.h>

using namespace std;

class IPackageElement {
    public:
        /** Returns the element as a json value.
            @return A Json::Value representation of this instance.*/
        virtual Json::Value jsonExport() = 0;
        
        /** Displays the element to the console in a human-readable way.
            @param indexes The selected path. */
        virtual void display(int indexes[2]) = 0;

        /** Sets an instance field.
            @param index The index of the field to edit.
            @param value A string representation of the new value.*/
        virtual void setField(int index, string value) = 0;
};
#endif
