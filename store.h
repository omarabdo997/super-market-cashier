#ifndef STORE_H
#define STORE_H
#include "item.h"

class Store
{
    Item* items;
    int* size;
    QString sellings[1000];
public:

    Store();
    Store(Item *items,int* size);
    QStringList display();
    void add_item(Item item);
    Item get_item(int n);
    void update_item(Item item,int n);
    void delete_item(int n);
    void set_sellings(QString selling,int n);
    QString display_sellings(int n);
};

#endif // STORE_H
