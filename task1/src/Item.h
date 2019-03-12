#pragma once
#include <iostream>
#include "Date.h"
using namespace std;

class Item {
private:
    char Group; // any from range 'a'...'z'
    int Subgroup; // any from range 0...99
    string Name; // any, but not empty
    Date Timestamp; // any
public:
    Item();
    Item(char, int, string, Date);
    string GetName(void);
    char GetGroup(void);
    int GetSubGroup(void);
    Date GetTimestamp(void);
    string ToString(void);
//    bool operator<(const Item &) const;
};

