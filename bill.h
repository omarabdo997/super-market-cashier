#ifndef BILL_H
#define BILL_H
#include "timestamp.h"
#include "item.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


class Bill
{
    TimeStamp date_time;
public:
    Bill();
    QString make_bill(Item items[], int size, QString name, float price, float paid, bool delivery, float delivery_fee);
};

#endif // BILL_H
