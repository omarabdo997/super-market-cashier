#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include <QMessageBox>
#include "login.h"
#include "storemenu.h"
#include "controller.h"
#include "item.h"
#include "menu.h"
#include "cart.h"
#include "timestamp.h"
#include <iostream>
#include "customer.h"
#include "store.h"
#include "global.h"
#include "QWidgetItem"
#include <QList>
#include "confirmationmenu.h"


//User *user;
//Controller controller;
//Menu menu;
//Cart cart;
//Customer customer;
//Store store;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    controller.connection();

        login log;
        log.setModal(true);
        log.exec();
        if(!user->isLoggedin())
        {
            this->~MainWindow();
        }
        if(user->isAdmin())
        {
            ui->pushButton_6->setEnabled(true);
        }
        else
        {
            ui->pushButton_6->setEnabled(false);
        }
        QPixmap bkgnd(":/new/prefix4/images.jpg");
            QSize size;
            size.setWidth(1920);
            size.setHeight(1080);
            bkgnd = bkgnd.scaled(size, Qt::IgnoreAspectRatio);
            QPalette palette;
            palette.setBrush(QPalette::Background, bkgnd);
            this->setPalette(palette);

//        this->centralWidget()->setStyleSheet("background-image:url(:/new/prefix4/images.jpg); background-position: center; ");
        ui->label_9->hide();
        ui->label_11->hide();
        ui->lineEdit_4->setReadOnly(true);
        ui->textEdit_2->setReadOnly(true);
        ui->radioButton->hide();
        ui->radioButton_2->hide();
        ui->label_10->hide();
        ui->pushButton_5->hide();
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);

        menu=controller.retrieve_menu();
        if(user->isAdmin())
        {
            store=Store(menu.get_items(),menu.get_size_address());
        }
        ui->treeWidget->setColumnWidth(0,280);
        ui->treeWidget->setColumnWidth(1,75);
        ui->treeWidget_2->setColumnWidth(0,280);
//91.6.115





        for(int i=0;i<menu.get_size();i++)
        {

            item[i]=new QTreeWidgetItem();
            item[i]->setText(0,menu.get_item(i).get_name());
            item[i]->setText(1,QString::number(menu.get_item(i).get_selling_price()));
            ui->treeWidget->insertTopLevelItem(i,item[i]);



        }
//        ui->treeWidget->setStyleSheet("QHeaderView::section {background-color:red}");






















}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    int quantity=ui->lineEdit_2->text().toInt();
    int row=ui->treeWidget->currentIndex().row();
    TimeStamp now;


    if(row!=-1)
    {
        cart.add_item(menu,quantity,row);
        ui->lineEdit_2->clear();

        ui->treeWidget_2->clear();
        for(int i=0;i<cart.get_size();i++)
        {
            cart_items[i]=new QTreeWidgetItem();
            cart_items[i]->setText(0,cart.get_item(i).get_name());
            cart_items[i]->setText(1,QString::number(cart.get_item(i).get_quantity()));
            cart_items[i]->setText(2,QString::number(cart.get_item(i).get_quantity()*cart.get_item(i).get_selling_price()));
            ui->treeWidget_2->insertTopLevelItem(i,cart_items[i]);



        }
    }


}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    for(int i=0;i<menu.get_size();i++)
    {
        if(item[i]->text(0).contains(arg1))
        {
            item[i]->setHidden(false);
        }
        else
        {
            item[i]->setHidden(true);
        }
    }



}

void MainWindow::on_pushButton_2_clicked()
{
    int row=ui->treeWidget_2->currentIndex().row();

    int quantity=ui->lineEdit_2->text().toInt();
    if(row!=-1)
    {
        cart.remove_item(menu,quantity,row);
        ui->lineEdit_2->clear();
        ui->treeWidget_2->clear();

        for(int i=0;i<cart.get_size();i++)
        {
            cart_items[i]=new QTreeWidgetItem();

            cart_items[i]->setText(0,cart.get_item(i).get_name());
            cart_items[i]->setText(1,QString::number(cart.get_item(i).get_quantity()));
            cart_items[i]->setText(2,QString::number(cart.get_item(i).get_quantity()*cart.get_item(i).get_selling_price()));
            ui->treeWidget_2->insertTopLevelItem(i,cart_items[i]);



        }

    }

}

void MainWindow::on_pushButton_3_clicked()
{
    if(cart.get_size()==0)
    {
        QMessageBox::warning(this,"No items","Select items first!");
    }
    else
    {
        ConfirmationMenu confirmation_menu;
        confirmation_menu.exec();
        if(confirme==1)
        {
            controller.make_selling(cart,customer);
            QMessageBox::information(this,"message",cart.make_selling(user->get_name(),paid,delivery,delivery_fee,promocode_discount));
            promocode_discount=0;
            ui->treeWidget_2->clear();
            ui->textEdit_2->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_3->clear();
            ui->label_9->hide();
            ui->label_11->hide();
            ui->lineEdit_4->setReadOnly(true);
            ui->textEdit_2->setReadOnly(true);
            ui->radioButton->hide();
            ui->radioButton_2->hide();
            ui->label_10->hide();
            ui->pushButton_5->hide();
            ui->lineEdit_4->clear();
            ui->textEdit_2->clear();
            ui->radioButton->setEnabled(false);
            ui->radioButton_2->setEnabled(false);
            customer=Customer();

            cart=Cart();
            cart.set_size(0);
        }

    }


}

void MainWindow::on_pushButton_4_clicked()
{
    if(controller.retrieve_customer(customer,ui->lineEdit_3->text()))
    {
        ui->textEdit_2->setText(customer.get_address());
        ui->lineEdit_4->setText(customer.get_name());
        ui->label_9->hide();
        ui->label_11->hide();
        ui->lineEdit_4->setReadOnly(true);
        ui->textEdit_2->setReadOnly(true);
        ui->radioButton->hide();
        ui->radioButton_2->hide();
        ui->label_10->hide();
        ui->pushButton_5->hide();
        ui->radioButton->setAutoExclusive(false);
        ui->radioButton_2->setAutoExclusive(false);
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);
        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(false);
        ui->radioButton->setAutoExclusive(true);
        ui->radioButton_2->setAutoExclusive(true);
        if(customer.isSpecial())
        {
            ui->label_9->show();
        }
    }
    else
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"Create new customer?","No user found with this phone number create new user with this phone number?");
        if(reply==QMessageBox::Yes)
        {
            ui->label_9->hide();
            ui->label_11->show();
            ui->lineEdit_4->setReadOnly(false);
            ui->textEdit_2->setReadOnly(false);
            ui->lineEdit_4->clear();
            ui->textEdit_2->clear();
            ui->radioButton->show();
            ui->radioButton_2->show();
            ui->label_10->show();
            ui->pushButton_5->show();
            if(user->isAdmin())
            {
                ui->radioButton->setEnabled(true);
                ui->radioButton_2->setEnabled(true);
            }
        }
        else
        {

        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->lineEdit_3->text()=="")
    {

    }
    else
    {
        int is_special;
        if(ui->radioButton->isChecked())
        {
            is_special=1;
        }
        else
        {
            is_special=0;
        }
        if(ui->lineEdit_4->text()=="")
        {
            QMessageBox::critical(this,"No name","Please fill the name field!");
        }
        else
        {
            customer=controller.add_customer(ui->lineEdit_4->text(),ui->lineEdit_3->text(),ui->textEdit_2->toPlainText(),is_special);
            controller.retrieve_customer(customer,ui->lineEdit_3->text());
            ui->label_9->hide();
            ui->label_11->hide();
            ui->lineEdit_4->setReadOnly(true);
            ui->textEdit_2->setReadOnly(true);
            ui->radioButton->hide();
            ui->radioButton_2->hide();
            ui->label_10->hide();
            ui->pushButton_5->hide();
            ui->radioButton->setAutoExclusive(false);
            ui->radioButton_2->setAutoExclusive(false);
            ui->radioButton->setEnabled(false);
            ui->radioButton_2->setEnabled(false);
            ui->radioButton->setChecked(false);
            ui->radioButton_2->setChecked(false);
            ui->radioButton->setAutoExclusive(true);
            ui->radioButton_2->setAutoExclusive(true);
            if(is_special==1)
            {
                ui->label_9->show();
            }



        }

    }


}

void MainWindow::on_pushButton_6_clicked()
{
    StoreMenu storeMenu;
    storeMenu.exec();
    ui->treeWidget->clear();
    for(int i=0;i<menu.get_size();i++)
    {

        item[i]=new QTreeWidgetItem();
        item[i]->setText(0,menu.get_item(i).get_name());
        item[i]->setText(1,QString::number(menu.get_item(i).get_selling_price()));
        ui->treeWidget->insertTopLevelItem(i,item[i]);



    }

}
