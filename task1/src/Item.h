#pragma once
#include <iostream>
#include "Date.h"
using namespace std;

class Item {
private:
    char group; // any from range 'a'...'z'
    int subgroup; // any from range 0...99
    string name; // any, but not empty
    // alternative: string *pname;
    // by the student's choice
    Date timestamp; // any
    // alternative: date *ptimestamp;
    // by the student's choice
public:
    Item(char, int, string, Date);
};

