#include "addmoditem.h"
#include "ui_addmoditem.h"
#include "global.h"
#include <QMessageBox>

AddModItem::AddModItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddModItem)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    if(selector==1)
    {
        ui->pushButton->hide();
        ui->lineEdit->setText(store.get_item(row).get_name());
        ui->lineEdit_2->setText(QString::number(store.get_item(row).get_selling_price()));
        ui->lineEdit_3->setText(QString::number(store.get_item(row).get_buying_price()));
        ui->lineEdit_4->setText(QString::number(store.get_item(row).get_quantity()));
    }

    if(selector==0)
    ui->pushButton_2->hide();
}

AddModItem::~AddModItem()
{
    delete ui;
}

void AddModItem::on_pushButton_clicked()
{
    bool new_name=1;
    for(int i=0;i<menu.get_size();i++)
    {
        if(ui->lineEdit->text()==store.get_item(i).get_name())
        {
            new_name=0;
            break;
        }
    }
    if(ui->lineEdit->text()!="" and ui->lineEdit_2->text()!="" and ui->lineEdit_3->text()!="" and ui->lineEdit_4->text()!="" and new_name==1)
    {
        controller.add_to_store(store,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text());
        close();
    }
    else if(new_name==0)
    {
        QMessageBox::information(this,"Name exists","This item name already exists");
    }
    else
    {
        QMessageBox::critical(this,"error","Fill all the fields");
    }

}

void AddModItem::on_pushButton_2_clicked()
{
    bool new_name=1;
    for(int i=0;i<menu.get_size();i++)
    {
        if(ui->lineEdit->text()==store.get_item(i).get_name())
        {
            if(row!=i)
            {
                new_name=0;
                break;
            }

        }
    }
    if(ui->lineEdit->text()!="" and ui->lineEdit_2->text()!="" and ui->lineEdit_3->text()!="" and ui->lineEdit_4->text()!="" and new_name==1)
    {
        controller.update_in_store(store,row,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text());
        close();
    }
    else if(new_name==0)
    {
        QMessageBox::information(this,"Name exists","This item name already exists");
    }
    else
    {
        QMessageBox::critical(this,"error","Fill all the fields");
    }
}
