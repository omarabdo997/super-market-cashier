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
#include <QTreeWidgetItem>

extern User *user;
extern Controller controller;
extern Menu menu;
extern Cart cart;
extern Customer customer;
extern Store store;
extern int row;
extern int selector;
extern QTreeWidgetItem* item[10000];
//extern QTreeWidgetItem* store_items[10000];
extern QTreeWidgetItem* cart_items[100];
extern float paid;
extern float delivery_fee;
extern bool delivery;
extern float promocode_discount;



#endif // GLOBAL_H
