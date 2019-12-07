#include "menu.h"

Menu::Menu()
{

}
Menu::Menu(Item items[],int size)
{
    for(int i=0;i<size;i++)
    {
        this->items[i]=items[i];
    }
    this->size=size;
}
QStringList Menu::display()
{
    QStringList lst;

    for(int i=0;i<size;i++)
    {
        lst.append(items[i].displayWithPrice());

    }
    return lst;
}
Item Menu::get_item(int n)
{
    return items[n];
}
void Menu::set_item_quantity(int n,float q)
{
    items[n].set_quantity(q);
}
Item* Menu::get_items()
{
    return items;
}
int Menu::get_size()
{
    return size;
}
int* Menu::get_size_address()
{
    return &size;
}

