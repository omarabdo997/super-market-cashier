#ifndef MENU_H
#define MENU_H
#include "item.h"
#include "QList"
#include "QString"

class Menu
{
private:

    Item items[10000];

    int size;
public:
    Menu();
    Menu(Item items[],int size);
    QStringList display();
    Item get_item(int n);
    Item* get_items();
    void set_item_quantity(int n,float q);
    int get_size();
    int* get_size_address();

};

#endif // MENU_H
