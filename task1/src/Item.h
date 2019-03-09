#pragma once
#include <iostream>
#include "Date.h"
using namespace std;

class Item {
private:
    char group; // any from range 'a'...'z'
    int subgroup; // any from range 0...99
    string name; // any, but not empty
    Date timestamp; // any
public:
    Item();
    Item(char, int, string, Date);
    string getName(void);
    char getGroup(void);
    int getSubGroup(void);
    Date getTimestamp(void);
    string toString(void);
};

