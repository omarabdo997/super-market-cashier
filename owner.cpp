#include "owner.h"

Owner::Owner(QString name,QString phone,QString username,int is_logged_in,int is_admin):User(name,phone,username,is_logged_in,is_admin)
{

}
void Owner::set_store(Store store)
{
    this->store=store;
}
