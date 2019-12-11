#include "bill.h"


Bill::Bill()
{

}
QString Bill::make_bill(Item items[],int size,QString name,float price,float paid,bool delivery,float delivery_fee)
{
    QString sellings="----------------------------------------------------------------------------------\nitem\t\t\t\t\t\tquantity\t\tprice\n__________________________________________________________________________________\n";
    //std::ostringstream oss;
    for(int i=0;i<size;i++)
    {
        QString name=items[i].get_name();
        QString complete;

        //name.resize(50,' ');



        complete=complete.fill('\t',6-(name.size()/8));

        sellings+=name+complete+QVariant(items[i].get_quantity()).toString()+"\t\t"+QVariant(items[i].get_quantity()*items[i].get_selling_price()).toString()+"\n";
        //oss<<std::setw(50)<<std::left<<name.toStdString()<<"\t"<<std::setw(5)<<std::left<<items[i].get_quantity()<<std::setw(5)<<std::left<<items[i].get_quantity()*items[i].get_selling_price()<<"\n";


    }
    //sellings+=QString::fromStdString(oss.str());
    if(!delivery)
    {
        sellings+="\n\n\n"+date_time.get_formate()+"\t\t\t\tTotal Price: "+QVariant(price).toString()+"\n"+"Cashier: "+name+"\t\t\t"+"Paid: "+QVariant(paid).toString()+"\n"+"\t\t\t\t\t\tChange: "+QVariant(paid-price).toString();
    }
    else
    {
        sellings+="\n\n\n"+date_time.get_formate()+"\t\t\t\tPrice: "+QVariant(price).toString()+"\n"+"Cashier: "+name+"\t\t\t"+"Delivery fee: "+QVariant(delivery_fee).toString()+"\n"+"\t\t\t\t\t\tTotal Price: "+QVariant(price+delivery_fee).toString();
    }

    return sellings;
}

