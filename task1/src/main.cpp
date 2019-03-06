#include "Date.h"
#include "Item.h"
#include <iostream>

using namespace std;

int main(void){
    Date begin = Date(1,2,1999);
    Date end = Date(3,3,2019);
    Date random_d = Date::CreateRandomDate(begin, end);
    cout << random_d.GetDay() << endl;
    cout << random_d.GetMonth() << endl;
    cout << random_d.GetYear() << endl;
//    Item item = new Item('a',0 , "charlie", random_d);

    cout << "a" << endl;
//    cout << "group: " << item.group << endl;
//    cout << "subgroup: " << item.subgroup << endl;
//    cout << "timestamp: " << item.timestamp << endl;
//    cout << "name: " << item.name << endl;
}

