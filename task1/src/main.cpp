#include "Date.h"
#include <iostream>

using namespace std;

int main(void){
    Date begin = Date(1,2,1999);
    Date end = Date(3,3,2019);
    Date random_d = Date::CreateRandomDate(begin, end);
//    cout << random_d.GetDay() << endl;
//    cout << random_d.GetMonth() << endl;
//    cout << random_d.GetYear() << endl;
    cout << random_d.ToString() << endl;
}

