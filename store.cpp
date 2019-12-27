#include "store.h"


Store::Store()
{

}
Store::Store(Item *items,int* size):items(items),size(size)
{

}
QStringList Store::display()
{
    QStringList lst;

    for(int i=0;i<(*size);i++)
    {
        lst.append(items[i].displayAll());

    }
    return lst;
}
void Store::add_item(Item item)
{
    items[(*size)++]=item;
}

Item Store::get_item(int n)
{
    return items[n];
}
void Store::update_item(Item item,int n)
{
    items[n]=item;
}
void Store::delete_item(int n)
{
    (*size)--;
    for(int i=n;i<(*size);i++)
    {
        items[i]=items[i+1];
    }
}
void Store::set_sellings(QString selling, int n)
{
    sellings[n]=selling;
}
QString Store::display_sellings(int n)
{
    return sellings[n];
}
