#include <iostream>
#include "Item.h"
#include "Date.h"

using namespace std;

Item::Item(char c, int i, string s, Date d) {
    group = c;
    subgroup = i;
    name = s;
    timestamp = d;
}

