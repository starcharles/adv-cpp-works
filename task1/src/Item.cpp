#include <iostream>
#include "Item.h"
#include "Date.h"

using namespace std;

Item::Item() {

}

Item::Item(char c, int i, string s, Date d) {
    Group = c;
    Subgroup = i;
    Name = s;
    Timestamp = d;
}

string Item::GetName() {
    return Name;
}

char Item::GetGroup() {
    return Group;
}

int Item::GetSubGroup() {
    return Subgroup;
}

Date Item::GetTimestamp() {
    return Timestamp;
}

string Item::ToString() {
    return "Name: " + Name + ","\
           "Group: " + Group + ","\
           "SubGroup: " + std::to_string(Subgroup) + ","\
           "Timestamp: " + Timestamp.ToString();
}
