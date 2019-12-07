#include "storemenu.h"
#include "ui_storemenu.h"
#include "global.h"
#include "addmoditem.h"
#include <QMessageBox>

StoreMenu::StoreMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoreMenu)
{
    ui->setupUi(this);
    ui->listWidget->addItems(store.display());
    ui->label_4->setText(controller.retrieve_profit());
    ui->label_6->setText(controller.retrieve_capital());

}

StoreMenu::~StoreMenu()
{
    delete ui;
}

void StoreMenu::on_pushButton_clicked()
{
    selector=0;
    AddModItem addmod;
    addmod.exec();
    ui->listWidget->clear();
    ui->listWidget->addItems(store.display());


}

void StoreMenu::on_pushButton_2_clicked()
{
    selector=1;
    row=ui->listWidget->currentRow();
    AddModItem addmod;
    addmod.exec();
    ui->listWidget->clear();
    ui->listWidget->addItems(store.display());
}

void StoreMenu::on_pushButton_3_clicked()
{
    row=ui->listWidget->currentRow();
    controller.delete_in_store(store,row);
    ui->listWidget->clear();
    ui->listWidget->addItems(store.display());
}

void StoreMenu::on_pushButton_4_clicked()
{
    QMessageBox::information(this,"Recipt",store.display_sellings(ui->listWidget_2->currentRow()));
}

void StoreMenu::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{
    QMessageBox::information(this,"Recipt",store.display_sellings(ui->listWidget_2->currentRow()));
}

void StoreMenu::on_pushButton_5_clicked()
{
    ui->listWidget_2->clear();
    ui->listWidget_2->addItems(controller.retrieve_sellings_history(store,ui->lineEdit->text(),ui->lineEdit_2->text()));
}
