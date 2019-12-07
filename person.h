#ifndef PERSON_H
#define PERSON_H
#include <QString>


class Person
{
private:
    QString name;
    QString phone;

public:
    Person();
    Person(QString name);
    Person(QString name,QString phone);
    void set_name(QString name);
    QString get_name();
    void set_phone(QString phone);
    QString get_phone();

};

#endif // PERSON_H
