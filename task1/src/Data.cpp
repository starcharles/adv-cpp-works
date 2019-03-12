#include "Data.h"
#include "Item.h"
#include <vector>

using namespace std;

Data::Data(int n) {
    pItems = new vector<Item>(n);
}

Data::~Data() {
    delete pItems;
}

void Data::PrintAll() const {
    std::for_each(this->pItems->begin(), this->pItems->end(),
                  [](Item &item) { std::cout << item.GetName() << std::endl; });
}

int Data::CountAll() const {
    return this->pItems->size();
}

vector <Item> Data::GetGroup(char a) const {
    vector <Item> group(0);
    auto addGroup = [&](Item &item) {
        char g = item.GetGroup();
        if (strcmp(&g, &a) == 0) {
            group.push_back(item);
        }
    };
    for_each(pItems->begin(), pItems->end(), addGroup);
    return group;
}

bool Data::PrintGroup(char c) const {
    vector <Item> group = this->GetGroup(c);

    if (group.size() == 0) {
        return false;
    }

    // print items
    for_each(group.begin(), group.end(), [](Item &item) {
        cout << item.ToString() << endl;
    });

    return true;
};

int Data::CountGroup(char g) {
    return count_if(pItems->begin(), pItems->end(), [&](Item &item) {
        char group = item.GetGroup();
        return strcmp(&group, &g) == 0;
    });
};

vector <Item> Data::GetSubgroup(char g, int sg) {
    vector <Item> subgroup(0);
    auto addSubGroup = [&](Item &item) {
        char gr = item.GetGroup();

        if (strcmp(&g, &gr) == 0 && sg == item.GetSubGroup()) {
            subgroup.push_back(item);
        }
    };
    for_each(pItems->begin(), pItems->end(), addSubGroup);
    return subgroup;

};

bool Data::PrintSubgroupByNames(char g, int sg) {
    vector <Item> group = this->GetSubgroup(g, sg);
    if (group.size() == 0) {
        return false;
    }

    sort(group.begin(),group.end(),[](Item &item1, Item &item2)-> bool {
        return item1.GetName() < item2.GetName();
    });

    // print items
    for_each(group.begin(), group.end(), [](Item &item) {
        cout << item.ToString() << endl;
    });

    return true;
};

bool Data::PrintSubgroupByDates(char g, int sg) {
    vector <Item> group = this->GetSubgroup(g, sg);
    if (group.size() == 0) {
        return false;
    }

    sort(group.begin(),group.end(),[](Item &item1, Item &item2)-> bool {
        return item1.GetTimestamp() < item2.GetTimestamp();
    });

    // print items
    for_each(group.begin(), group.end(), [](Item &item) {
        cout << item.ToString() << endl;
    });

    return true;
};

int Data::CountSubgroup(char g, int sg) {
    vector <Item> group = this->GetSubgroup(g, sg);
    return group.size();
};

Item *Data::GetItem(char g, int sg, string n) {
    auto itr = find_if(pItems->begin(), pItems->end(), [&](Item &item) {
        char gr = item.GetGroup();
        return strcmp(&g, &gr) == 0 && sg == item.GetSubGroup() && item.GetName() == n;
    });
    if (itr == pItems->end()) {
        return nullptr;
    }

    // NOTE:
    //error: no viable conversion from returned value of type
    //'std::__1::__wrap_iter<Item *>' to function return type 'Item *'
    //return it;

    return &(*itr);
};

Item *Data::GetItem(char g, int sg, Date d) {
    auto itr = find_if(pItems->begin(), pItems->end(), [&](Item &item) {
        char gr = item.GetGroup();
        return strcmp(&g, &gr) == 0 && sg == item.GetSubGroup() && item.GetTimestamp() == d;
    });
    if (itr == pItems->end()) {
        return nullptr;
    }
    return &(*itr);
};

bool Data::PrintItem(char g, int sg, string n) {
    Item *item = GetItem(g, sg, n);
    if (item == nullptr) return false;
    cout << item->ToString() << endl;
    return true;
};

bool Data::PrintItem(char g, int sg, Date d) {
    Item *item = GetItem(g, sg, d);
    if (item == nullptr) return false;
    cout << item->ToString() << endl;
    return true;
}

bool Data::RemoveGroup(char g) {
    int initialSize = pItems->size();
    int i = 0;
    for_each(pItems->begin(), pItems->end(), [&](Item &item) {
        char gr = item.GetGroup();
        if (strcmp(&g, &gr) == 0) {
            pItems->erase(pItems->begin() + i);
        }
        i++;
    });
    return initialSize != pItems->size();
};

bool Data::RemoveSubgroup(char g, int sg) {
    int initialSize = pItems->size();
    int i = 0;
    for_each(pItems->begin(), pItems->end(), [&](Item &item) {
        char gr = item.GetGroup();
        if (strcmp(&g, &gr) == 0 && item.GetSubGroup() == sg) {
            pItems->erase(pItems->begin() + i);
        }
        i++;
    });
    return initialSize != pItems->size();
};

bool Data::RemoveItem(char g, int sg, string n) {
    auto itr = find_if(pItems->begin(), pItems->end(), [&](Item &item) {
        char gr = item.GetGroup();
        return strcmp(&g, &gr) == 0 && sg == item.GetSubGroup() && item.GetName() == n;
    });
    if(itr == pItems->end()){
        return false;
    }
    pItems->erase(itr);
    return true;
};

bool Data::RemoveItem(char g, int sg, Date d) {
    auto itr = find_if(pItems->begin(), pItems->end(), [&](Item &item) {
        char gr = item.GetGroup();
        return strcmp(&g, &gr) == 0 && sg == item.GetSubGroup() && item.GetTimestamp() == d;
    });
    if(itr == pItems->end()){
        return false;
    }
    pItems->erase(itr);
    return true;
};
