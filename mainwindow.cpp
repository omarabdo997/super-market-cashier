#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include <QMessageBox>
#include "login.h"
#include "storemenu.h"
#include "controller.h"
#include "item.h"
#include "menu.h"
#include "qdebug.h"
#include "cart.h"
#include "timestamp.h"
#include <iostream>
#include "customer.h"
#include "store.h"
#include "global.h"

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
        ui->label_9->hide();
        ui->label_11->hide();
        ui->textEdit->hide();
        ui->textEdit_2->hide();
        ui->radioButton->hide();
        ui->radioButton_2->hide();
        ui->label_10->hide();
        ui->pushButton_5->hide();
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);
        //ui->radioButton->setAutoExclusive(false);
        //ui->radioButton_2->setAutoExclusive(false);
        menu=controller.retrieve_menu();
        if(user->isAdmin())
        {
            store=Store(menu.get_items(),menu.get_size_address());
        }










    ui->listWidget->addItems(menu.display());










}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    int quantity=ui->lineEdit_2->text().toInt();
    int row=ui->listWidget->currentRow();
    TimeStamp now;
    qDebug()<<now.get_formate();

    if(row!=-1)
    {
        cart.add_item(menu,quantity,row);
        ui->listWidget_2->clear();
        ui->lineEdit_2->clear();
        qDebug()<<"New"<<menu.get_item(row).get_quantity();
        ui->listWidget_2->addItems(cart.display());
    }

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    for(int i=0;i<ui->listWidget->count();i++)
    {
        if(ui->listWidget->item(i)->text().contains(arg1))
        {
            ui->listWidget->item(i)->setHidden(false);
        }
        else
        {
            ui->listWidget->item(i)->setHidden(true);
        }
    }



}

void MainWindow::on_pushButton_2_clicked()
{
    int row=ui->listWidget_2->currentRow();
    qDebug()<<"row"<<row;
    int quantity=ui->lineEdit_2->text().toInt();
    if(row!=-1)
    {
        cart.remove_item(menu,quantity,row);
        ui->listWidget_2->clear();
        ui->listWidget_2->addItems(cart.display());
        ui->lineEdit_2->clear();
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    if(cart.get_item(0).get_quantity()==0)
    {
        QMessageBox::warning(this,"No items","Select items first!");
    }
    else
    {
        controller.make_selling(cart,customer);
        QMessageBox::information(this,"message",cart.make_selling());
        ui->listWidget_2->clear();
        ui->textBrowser->clear();
        ui->textBrowser_2->clear();
        ui->lineEdit_3->clear();
        ui->label_9->hide();
        ui->label_11->hide();
        ui->textEdit->hide();
        ui->textEdit_2->hide();
        ui->radioButton->hide();
        ui->radioButton_2->hide();
        ui->label_10->hide();
        ui->pushButton_5->hide();
        ui->textEdit->clear();
        ui->textEdit_2->clear();
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);
        customer=Customer();

        cart=Cart();
    }


}

void MainWindow::on_pushButton_4_clicked()
{
    if(controller.retrieve_customer(customer,ui->lineEdit_3->text()))
    {
        ui->textBrowser->setText(customer.get_address());
        ui->textBrowser_2->setText(customer.get_name());
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
            ui->label_11->show();
            ui->textEdit->show();
            ui->textEdit_2->show();
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
            qDebug()<<"Ma7asalsh";
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
        if(ui->textEdit->toPlainText()=="")
        {
            QMessageBox::critical(this,"No name","Please fill the name field!");
        }
        else
        {
            customer=controller.add_customer(ui->textEdit->toPlainText(),ui->lineEdit_3->text(),ui->textEdit_2->toPlainText(),is_special);
            controller.retrieve_customer(customer,ui->lineEdit_3->text());
            ui->label_9->hide();
            ui->label_11->hide();
            ui->textEdit->hide();
            ui->textEdit_2->hide();
            ui->radioButton->hide();
            ui->radioButton_2->hide();
            ui->label_10->hide();
            ui->pushButton_5->hide();
            ui->textEdit->clear();
            ui->textEdit_2->clear();
            ui->radioButton->setAutoExclusive(false);
            ui->radioButton_2->setAutoExclusive(false);
            ui->radioButton->setEnabled(false);
            ui->radioButton_2->setEnabled(false);
            ui->radioButton->setChecked(false);
            ui->radioButton_2->setChecked(false);
            ui->radioButton->setAutoExclusive(true);
            ui->radioButton_2->setAutoExclusive(true);

            ui->textBrowser_2->setText(customer.get_name());
            ui->textBrowser->setText(customer.get_address());
        }

    }


}

void MainWindow::on_pushButton_6_clicked()
{
    StoreMenu storeMenu;
    storeMenu.exec();
    ui->listWidget->clear();
    ui->listWidget->addItems(menu.display());
}
