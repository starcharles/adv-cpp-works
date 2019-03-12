#pragma once
#include "Item.h"

using namespace std;

class Data{
private:
    vector<Item> *pItems;
public:
    Data(int);
    ~Data();
    void PrintAll() const;
    int CountAll() const;
    vector<Item> GetGroup(char) const;
    bool PrintGroup(char) const;
    int CountGroup(char g);
    vector<Item> GetSubgroup(char g, int sg);
    bool PrintSubgroupByNames(char g, int sg);
    bool PrintSubgroupByDates(char g, int sg);
    int CountSubgroup(char g, int sg);
    Item* GetItem(char g, int sg, string n);
    Item* GetItem(char g, int sg, Date d);
    bool PrintItem(char g, int sg, string n);
    bool PrintItem(char g, int sg, Date d);
    bool RemoveGroup(char g);
    bool RemoveSubgroup(char g, int sg);
    bool RemoveItem(char g, int sg, string n);
    bool RemoveItem(char g, int sg, Date d);
};