#ifndef USER_H
#define USER_H
#include "person.h"
#include "store.h"
class User:public Person
{
private:
    QString username;
    bool is_logged_in;
    bool is_admin;
public:
    User();
    User(QString name,QString phone,QString username,bool is_logged_in,bool is_admin);
    void set_username(QString username);
    QString get_username();
    void log_in();
    void log_out();
    bool isLoggedin();
    bool isAdmin();
    virtual void set_store(Store store)=0;
};

#endif // USER_H
