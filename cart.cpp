#include "cart.h"

Cart::Cart():size(0)
{

}
void Cart::add_item(Menu& menu,int quantity,int n)
{
    int flag=0;
    if(quantity==0)
    {
        quantity=1;
    }
    Item item=menu.get_item(n);
    for(int i=0;i<size;i++)
    {
        if (items[i].get_name()==item.get_name())
        {
            items[i]=Item(item.get_name(),item.get_selling_price(),item.get_buying_price(),items[i].get_quantity()+quantity);
            menu.set_item_quantity(n,item.get_quantity()-quantity);
            flag=1;
            break;
        }

    }
    if(flag==0)
    {
        cart_menu.insert(item.get_name(),n);




        items[size++]=Item(item.get_name(),item.get_selling_price(),item.get_buying_price(),quantity);
        menu.set_item_quantity(n,item.get_quantity()-quantity);

    }


}
void Cart::set_size(int s)
{
    size=s;
}
QStringList Cart::display()
{
    QStringList lst;

    for(int i=0;i<size;i++)
    {
        lst.append(items[i].displayWithQuantity());

    }
    return lst;
}
void Cart::remove_item(Menu& menu,float quantity,int row)
{

    int id=cart_menu[items[row].get_name()];

    Item item=menu.get_item(id);
    if(quantity==0 or quantity==items[row].get_quantity())
    {

        menu.set_item_quantity(id,item.get_quantity()+items[row].get_quantity());
        size--;
        for(int i=row;i<size;i++)
        {
            items[i]=items[i+1];
        }
    }
    else if(quantity<items[row].get_quantity())
    {
        menu.set_item_quantity(id,item.get_quantity()+quantity);
        items[row].set_quantity(items[row].get_quantity()-quantity);
    }

}
QString Cart::make_selling(QString name,float paid,bool delivery,float delivery_fee,float promocode_discount)
{

    return bill.make_bill(items,size,name,get_total_price(),paid,delivery,delivery_fee,promocode_discount);
}
float Cart::get_total_price()
{
    float total_price=0;
    for(int i=0;i<size;i++)
    {
        total_price+=items[i].get_quantity()*items[i].get_selling_price();
    }
    return  total_price;
}
float Cart::get_profit()
{
    float profit=0;
    for(int i=0;i<size;i++)
    {
        profit+=(items[i].get_quantity()*items[i].get_selling_price())-(items[i].get_quantity()*items[i].get_buying_price());

    }
    return profit;
}
int Cart::get_size()
{
    return size;
}
Item Cart::get_item(int n)
{
    return items[n];
}
