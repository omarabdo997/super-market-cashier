#ifndef ITEM_H
#define ITEM_H
#include <QString>
#include <QVariant>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Item
{
    QString name;
    float selling_price;
    float buying_price;
    float quantity;
public:
    Item();
    Item(QString name,float selling_price,float buying_price,float quantity);
    QString displayWithPrice();
    QString displayWithQuantity();
    QString displayAll();
    QString get_name();
    float get_selling_price();
    float get_buying_price();
    float get_quantity();
    void set_quantity(float n);




};

#endif // ITEM_H
