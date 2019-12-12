#include "addmoditem.h"
#include "ui_addmoditem.h"
#include "global.h"

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
    controller.add_to_store(store,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text());
    close();
}

void AddModItem::on_pushButton_2_clicked()
{
    controller.update_in_store(store,row,ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text());
    close();

}
