#include "controller.h"
#include "string"
#include "item.h"
#include "global.h"

using namespace std;


QString Controller::connection()
{
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "supermarket917356", "917356", "supermarket917356", 3306, NULL, 0);
    if(conn)
    {
        return "Connected";
    }
}
User* Controller::login(QString id,QString pass)
{

    sql="SELECT * from users where username='"+id+"'and password=md5('"+pass+"')";

    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
    res=mysql_store_result(conn);
    row=mysql_fetch_row(res);
    QString is_admin;



    if(row==NULL)
    {

        User* user=new Employee();



        return user;
    }
    else
    {

      is_admin=row[5];
    }

    if(is_admin=="0")
    {



        User* user=new Employee(row[1],row[2],row[3],1,0);


        return user;
    }
    else if(is_admin=="1")
    {


        User* user=new Owner(row[1],row[2],row[3],1,1);


        return user;

    }
}
Menu Controller::retrieve_menu()
{
    Item items[10000];

    sql="select * from items";
    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
    res=mysql_store_result(conn);
    int i=0;
    QString selling_price,buying_price,quantity;



    while(row=mysql_fetch_row(res))
    {

        selling_price=row[2];
        buying_price=row[3];
        quantity=row[4];
        items[i]=Item(row[1],selling_price.toFloat(),buying_price.toFloat(),quantity.toFloat());

        i++;

    }
    Menu menu(items,i);
    return menu;

}
void Controller::add_to_store(Store &store,QString name,QString selling_price,QString buying_price,QString quantity)
{
    sql="insert into items(name,selling_price,buying_price,quantity) values('"+name+"',"+selling_price+","+buying_price+","+quantity+")";
    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
    Item item(name,selling_price.toFloat(),buying_price.toFloat(),quantity.toFloat());
    store.add_item(item);


}
void Controller::update_in_store(Store &store,int row,QString name,QString selling_price,QString buying_price,QString quantity)
{
    sql="update items set name='"+name+"',selling_price="+selling_price+",buying_price="+buying_price+",quantity="+quantity+" where name='"+store.get_item(row).get_name()+"'";
    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
    Item item(name,selling_price.toFloat(),buying_price.toFloat(),quantity.toFloat());
    store.update_item(item,row);


}
void Controller::delete_in_store(Store &store,int row)
{
    sql="delete from items where name='"+store.get_item(row).get_name()+"'";
    arry=sql.toLocal8Bit();
    q=arry.data();
    result=mysql_query(conn,q);
    store.delete_item(row);

}

void Controller::make_selling(Cart cart,Customer customer)
{
    if(customer.get_phone()=="")
    {
        sql="insert into sellings(sellings,price,profit) values('"+cart.make_selling(user->get_name(),paid,delivery,delivery_fee,promocode_discount)+"',"+QString::number((cart.get_total_price()*(1-promocode_discount))+delivery_fee)+","+QString::number(cart.get_profit()-(cart.get_total_price()*promocode_discount))+")";
    }
    else
    {
        sql="insert into sellings(phone,sellings,price,profit) values('"+customer.get_phone()+"','"+cart.make_selling(user->get_name(),paid,delivery,delivery_fee,promocode_discount)+"',"+QString::number((cart.get_total_price()*(1-promocode_discount))+delivery_fee)+","+QString::number(cart.get_profit()-(cart.get_total_price()*promocode_discount))+")";
    }

    arry=sql.toLocal8Bit();
    q=arry.data();
    result=mysql_query(conn,q);
    for (int i=0;i<cart.get_size();i++)
    {
        sql="update items set quantity=quantity-"+QString::number(cart.get_item(i).get_quantity())+" where name='"+cart.get_item(i).get_name()+"'";
        arry=sql.toLocal8Bit();
        q=arry.data();
        result=mysql_query(conn,q);
    }
}
bool Controller::retrieve_customer(Customer &customer,QString phone)
{
    QString is_special;
    sql="select * from customers where phone='"+phone+"'";
    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
    res=mysql_store_result(conn);
    row=mysql_fetch_row(res);
    if(row!=NULL)
    {
        is_special=row[4];
        customer=Customer(row[1],row[2],row[3],is_special.toInt());
        return 1;
    }
    else
    {
        return 0;
    }


}
int Controller::retrieve_sellings_history(Store& store,QString from_date,QString to_date,QStringList lst[])
{



    QDate date1;
    QDate date2;
    date1=date1.fromString(from_date,"d-M-yyyy");

    date2=date2.fromString(to_date,"d-M-yyyy");
    date2=date2.addDays(1);
    sql="select * from sellings where date_time between '"+date1.toString("yyyy-MM-dd")+"' and '"+date2.toString("yyyy-MM-dd")+"'";

    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
    res=mysql_store_result(conn);
    int i=0;
    QString phone,sellings,date_time,price,profit,total;



    while(row=mysql_fetch_row(res))
    {
        phone=row[1];
        sellings=row[2];
        date_time=row[3];
        price=row[4];
        profit=row[5];
        lst[i].append(phone);
        lst[i].append(sellings);
        lst[i].append(date_time);
        lst[i].append(price);
        lst[i].append(profit);
        total=phone+"\t"+date_time+"\t"+price+"\t"+profit;


        store.set_sellings(sellings,i);

        i++;

    }
    return i;


}
Customer Controller::add_customer(QString name,QString phone,QString address,int is_special)
{
    Customer customer(name,phone,address,is_special);
    sql="insert into customers(name,phone,address,is_special) values('"+customer.get_name()+"','"+customer.get_phone()+"','"+customer.get_address()+"',"+QString::number(is_special)+")";
    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
    return customer;
}
QString Controller::retrieve_profit()
{
    QString total_profit;
    sql="Select sum(profit) from sellings";
    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
    res=mysql_store_result(conn);
    row=mysql_fetch_row(res);
    total_profit=row[0];
    return total_profit;

}
QString Controller::retrieve_capital()
{
    QString capital;
    sql="Select buying_price , quantity ,sum(buying_price * quantity) as total from items";
    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
    res=mysql_store_result(conn);
    row=mysql_fetch_row(res);
    capital=row[2];
    return capital;
}
float Controller::check_promocode(QString code)
{
    sql="select discount from promocodes where code='"+code+"'";
    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
    res=mysql_store_result(conn);
    row=mysql_fetch_row(res);
    if(row!=NULL)
    {
        QString discount=row[0];
        return discount.toFloat();
    }
    else
    {
        return 0;
    }
}
void Controller::remove_promocode(QString code)
{
    sql="Delete from promocodes where code='"+code+"'";
    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
}
void Controller::add_promocode(QString code,float discount)
{
    sql="insert into promocodes(code,discount) values('"+code+"',"+QString::number(discount)+")";
    arry=sql.toLocal8Bit();

    q=arry.data();
    result=mysql_query(conn,q);
}
