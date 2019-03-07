//
// Created by ns on 2019/03/07.
//

#include "Data.h"
#include "Item.h"
#include <vector>
using namespace std;

Data::Data(int n) {
    this->items = new vector<Item>(n);
}

Data::~Data() {
    delete this->items;
}

void Data::PrintAll() {
    std::for_each(this->items->begin(), this->items->end(), [](Item& item) { cout << item.name << endl;} );
}