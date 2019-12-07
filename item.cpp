#include "item.h"

Item::Item()
{

}
Item::Item(QString name,float selling_price,float buying_price,float quantity):name(name),selling_price(selling_price),buying_price(buying_price),quantity(quantity)
{

}
QString Item::displayWithPrice()
{
    QString name_formate=name;
    name_formate.truncate(13);
    return name_formate+"\t\t"+QVariant(selling_price).toString();
}
QString Item::displayWithQuantity()
{
    return name+"\t\t"+QVariant(quantity).toString();
}
QString Item::get_name()
{
    return name;
}
float Item::get_selling_price()
{
    return selling_price;
}
float Item::get_buying_price()
{
    return buying_price;
}
float Item::get_quantity()
{
    return quantity;
}
void Item::set_quantity(float n)
{
    quantity=n;
}
QString Item::displayAll()
{
    QString name_formate=name;
    name_formate.truncate(13);
    return name_formate+"\t\t"+QVariant(selling_price).toString()+"\t"+QVariant(buying_price).toString()+"\t"+QVariant(quantity).toString();
}
