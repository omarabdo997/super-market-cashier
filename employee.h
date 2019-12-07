#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "user.h"

class Employee:public User
{
private:

public:
    Employee();
    Employee(QString name,QString phone,QString username,int is_logged_in,int is_admin);
    void set_store(Store store);


};

#endif // EMPLOYEE_H
