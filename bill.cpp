#include "bill.h"

Bill::Bill()
{

}
QString Bill::make_bill(Item items[],int size)
{
    QString sellings="----------------------------------------------------------------------------------\nitem\t\t\t\t\t\tquantity\t\tprice\n__________________________________________________________________________________\n";
    //std::ostringstream oss;
    for(int i=0;i<size;i++)
    {
        QString name=items[i].get_name();
        name.resize(80,' ');

        sellings+=name+"\t"+QVariant(items[i].get_quantity()).toString()+"\t\t"+QVariant(items[i].get_quantity()*items[i].get_selling_price()).toString()+"\n";
        //oss<<std::setw(50)<<std::left<<name.toStdString()<<"\t"<<std::setw(5)<<std::left<<items[i].get_quantity()<<std::setw(5)<<std::left<<items[i].get_quantity()*items[i].get_selling_price()<<"\n";


    }
    //sellings+=QString::fromStdString(oss.str());
    sellings+="\n\n\n"+date_time.get_formate()+"\t\t\t\tTotal Price: ";
    return sellings;
}

