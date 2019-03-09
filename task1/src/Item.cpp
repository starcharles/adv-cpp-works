#include <iostream>
#include "Item.h"
#include "Date.h"

using namespace std;

Item::Item() {

}

Item::Item(char c, int i, string s, Date d) {
    group = c;
    subgroup = i;
    name = s;
    timestamp = d;
}

string Item::getName() {
    return name;
}

char Item::getGroup() {
    return group;
}

int Item::getSubGroup() {
    return subgroup;
}

Date Item::getTimestamp() {
    return timestamp;
}

string Item::toString() {
    return "Name: " + name + ","\
           "Group: " + group + ","\
           "SubGroup: " + std::to_string(subgroup) + ","\
           "Timestamp: " + timestamp.ToString();
}
