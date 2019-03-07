#include "Item.h"

class Data{
private:
    std::vector<Item> *items;
public:
    Data(int);
    ~Data();
    void PrintAll();
    void CountAll();
//    xxxx GetGroup(char);
    bool PrintGroup(char);
};