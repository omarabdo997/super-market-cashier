#ifndef OWNER_H
#define OWNER_H
#include "user.h"
#include "store.h"

class Owner:public User
{
    Store store;
public:
    Owner(QString name,QString phone,QString username,int is_logged_in,int is_admin);
    void set_store(Store store);

};

#endif // OWNER_H
