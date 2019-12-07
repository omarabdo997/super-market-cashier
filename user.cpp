#include "user.h"

User::User():is_logged_in(0),is_admin(0)
{

}

User::User(QString name,QString phone,QString username,bool is_logged_in,bool is_admin):Person(name,phone),username(username),is_logged_in(is_logged_in),is_admin(is_admin)
{

}
void User::set_username(QString username)
{
    this->username=username;
}

QString User::get_username()
{
    return username;
}
void User::log_in()
{
    is_logged_in=1;
}
void User::log_out()
{

}
bool User::isLoggedin()
{
    return is_logged_in;
}
bool User::isAdmin()
{
    return is_admin;
}

