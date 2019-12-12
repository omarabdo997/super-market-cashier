#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "mysql.h"
#include <QString>
#include "user.h"
#include "employee.h"
#include "owner.h"
#include "menu.h"
#include "cart.h"
#include "customer.h"
#include <QValidator>
class Controller
{
private:
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    QString sql;
    QByteArray arry;
    const char*q;
    int result;
public:
    QString connection();
    User* login(QString id,QString pass);
    Menu retrieve_menu();
    void make_selling(Cart cart,Customer customer);
    bool retrieve_customer(Customer& customer,QString phone);
    Customer add_customer(QString name,QString phone,QString address,int is_special);
    void add_to_store(Store &store,QString name,QString selling_price,QString buying_price,QString quantity);
    void update_in_store(Store &store,int row,QString name,QString selling_price,QString buying_price,QString quantity);
    void delete_in_store(Store &store,int row);
    int retrieve_sellings_history(Store& store,QString from_date,QString to_date,QStringList lst[]);
    QString retrieve_profit();
    QString retrieve_capital();
    float check_promocode(QString code);
};

#endif // CONTROLLER_H
