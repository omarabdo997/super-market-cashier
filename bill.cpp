#include "bill.h"


Bill::Bill()
{

}
QString Bill::make_bill(Item items[],int size,QString name,float price,float paid,bool delivery,float delivery_fee,float promocode_discount)
{
    QString sellings="----------------------------------------------------------------------------------\nitem\t\t\t\t\t\tquantity\t\tprice\n__________________________________________________________________________________\n";
    //std::ostringstream oss;
    int promopercentage=promocode_discount*100;

    for(int i=0;i<size;i++)
    {
        QString name=items[i].get_name();
        QString complete;

        //name.resize(50,' ');



        complete=complete.fill('\t',6-(name.size()/8));

        sellings+=name+complete+QString::number(items[i].get_quantity())+"\t\t"+QString::number(items[i].get_quantity()*items[i].get_selling_price())+"\n";
        //oss<<std::setw(50)<<std::left<<name.toStdString()<<"\t"<<std::setw(5)<<std::left<<items[i].get_quantity()<<std::setw(5)<<std::left<<items[i].get_quantity()*items[i].get_selling_price()<<"\n";


    }
    QString complete;
    complete=complete.fill('\t',5-(name.size()/8));
    //sellings+=QString::fromStdString(oss.str());
    if(!delivery)
    {
        if(promocode_discount!=0)
        {
            float total_price=price*(1-promocode_discount);
            float change=paid-total_price;

            sellings+="\n\n\n"+date_time.get_formate()+"\t\t\t\tPrice: "+QString::number(price)+"\n"+"Cashier: "+name+complete+"Promocode discount: "+QString::number(promopercentage)+"%"+"\n"+"\t\t\t\t\t\tTotal Price: "+QString::number(total_price)+"\n"+"\t\t\t\t\t\tPaid: "+QString::number(paid)+"\n"+"\t\t\t\t\t\tChange: "+QString::number(change);
        }
        else
        {
            sellings+="\n\n\n"+date_time.get_formate()+"\t\t\t\tTotal Price: "+QString::number(price)+"\n"+"Cashier: "+name+complete+"Paid: "+QString::number(paid)+"\n"+"\t\t\t\t\t\tChange: "+QString::number(paid-price);

        }
    }
    else
    {
        if(promocode_discount!=0)
        {
            sellings+="\n\n\n"+date_time.get_formate()+"\t\t\t\tPrice: "+QString::number(price)+"\n"+"Cashier: "+name+complete+"Promocode discount: "+QString::number(promopercentage)+"%"+"\n"+"\t\t\t\t\t\tNew Price: "+QString::number(price*(1-promocode_discount))+"\n"+"\t\t\t\t\t\tDelivery fee: "+QString::number(delivery_fee)+"\n"+"\t\t\t\t\t\tTotal Price: "+QString::number(price*(1-promocode_discount)+delivery_fee);

        }
        else
        {
            sellings+="\n\n\n"+date_time.get_formate()+"\t\t\t\tPrice: "+QString::number(price)+"\n"+"Cashier: "+name+complete+"Delivery fee: "+QString::number(delivery_fee)+"\n"+"\t\t\t\t\t\tTotal Price: "+QString::number(price+delivery_fee);

        }
    }

    return sellings;
}

