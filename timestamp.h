#ifndef TIMESTAMP_H
#define TIMESTAMP_H
#include <QTime>
#include <QDate>

class TimeStamp
{
    QTime time;
    QDate date;
public:
    TimeStamp();
    QString get_formate();
};

#endif // TIMESTAMP_H
