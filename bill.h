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
    QString make_bill(Item items[],int size);
};

#endif // BILL_H
