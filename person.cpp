#include "person.h"

Person::Person()
{

}
Person::Person(QString name)
{
    this->name=name;

}
Person::Person(QString name,QString phone)
{
    this->name=name;
    this->phone=phone;

}
void Person::set_name(QString name)
{
    this->name=name;
}
QString Person::get_name()
{
    return name;
}
void Person::set_phone(QString phone)
{
    this->phone=phone;
}
QString Person::get_phone()
{
    return phone;
}
