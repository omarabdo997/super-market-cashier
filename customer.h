#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "person.h"

class Customer:public Person
{
    QString address;
    bool is_special;
public:
    Customer();
    Customer(QString name,QString phone,QString address,bool is_special);
    QString get_address();
    void set_address(QString address);
    bool isSpecial();
};

#endif // CUSTOMER_H
