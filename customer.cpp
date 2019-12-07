#include "customer.h"

Customer::Customer()
{

}
Customer::Customer(QString name, QString phone, QString address, bool is_special):Person(name,phone),address(address),is_special(is_special)
{

}
QString Customer::get_address()
{
    return address;
}
void Customer::set_address(QString address)
{
    this->address=address;
}
bool Customer::isSpecial()
{
    return is_special;
}
