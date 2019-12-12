#include "global.h"



User *user;
Controller controller;
Menu menu;
Cart cart;
Customer customer;
Store store;
int row;
int selector;
QTreeWidgetItem* item[10000];
QTreeWidgetItem* cart_items[100];
float paid;
float delivery_fee=0;
bool delivery=0;
float promocode_discount=0;
bool confirme=0;
//QTreeWidgetItem* store_items[10000];
