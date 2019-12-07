#ifndef GLOBAL_H
#define GLOBAL_H
#include "controller.h"
#include "item.h"
#include "menu.h"
#include "qdebug.h"
#include "cart.h"
#include "timestamp.h"
#include <iostream>
#include "customer.h"
#include "store.h"

extern User *user;
extern Controller controller;
extern Menu menu;
extern Cart cart;
extern Customer customer;
extern Store store;
extern int row;
extern int selector;



#endif // GLOBAL_H
