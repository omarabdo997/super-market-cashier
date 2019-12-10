#ifndef CART_H
#define CART_H
#include "item.h"
#include "menu.h"
#include <QVariant>

#include <iostream>
#include <iterator>
#include <map>
#include "bill.h"


class Cart
{
private:
    Item items[100];
    QMap<QString,int>cart_menu;
    int size;
    Bill bill;
public:

    Cart();
    void add_item(Menu& menu,int quantity,int n);
    void set_size(int s);
    QStringList display();
    void remove_item(Menu& menu,float quantity,int row);
    QString make_selling();
    float get_total_price();
    float get_profit();
    int get_size();
    Item get_item(int n);

};

#endif // CART_H
