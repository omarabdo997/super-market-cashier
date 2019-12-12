#include "storemenu.h"
#include "ui_storemenu.h"
#include "global.h"
#include "addmoditem.h"
#include <QMessageBox>
#include <QUuid>

StoreMenu::StoreMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoreMenu)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnWidth(0,280);
    ui->treeWidget->setColumnWidth(1,85);
    ui->treeWidget->setColumnWidth(2,85);
    ui->treeWidget->setColumnWidth(3,75);
    QPixmap bkgnd(":/new/prefix4/images.jpg");
        QSize size;
        size.setWidth(1920);
        size.setHeight(1080);
        bkgnd = bkgnd.scaled(size, Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    QTreeWidgetItem* store_items;

    for(int i=0;i<menu.get_size();i++)
    {
        store_items=new QTreeWidgetItem();
        store_items->setText(0,store.get_item(i).get_name());
        store_items->setText(1,QString::number(store.get_item(i).get_selling_price()));
        store_items->setText(2,QString::number(store.get_item(i).get_buying_price()));
        store_items->setText(3,QString::number(store.get_item(i).get_quantity()));
        ui->treeWidget->insertTopLevelItem(i,store_items);
    }

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
    QTreeWidgetItem* store_items;
    ui->treeWidget->clear();
    for(int i=0;i<menu.get_size();i++)
    {
        store_items=new QTreeWidgetItem();
        store_items->setText(0,store.get_item(i).get_name());
        store_items->setText(1,QString::number(store.get_item(i).get_selling_price()));
        store_items->setText(2,QString::number(store.get_item(i).get_buying_price()));
        store_items->setText(3,QString::number(store.get_item(i).get_quantity()));
        ui->treeWidget->insertTopLevelItem(i,store_items);
    }


}

void StoreMenu::on_pushButton_2_clicked()
{
    selector=1;
    row=ui->treeWidget->currentIndex().row();
    AddModItem addmod;
    addmod.exec();
    QTreeWidgetItem* store_items;
    ui->treeWidget->clear();
    for(int i=0;i<menu.get_size();i++)
    {
        store_items=new QTreeWidgetItem();
        store_items->setText(0,store.get_item(i).get_name());
        store_items->setText(1,QString::number(store.get_item(i).get_selling_price()));
        store_items->setText(2,QString::number(store.get_item(i).get_buying_price()));
        store_items->setText(3,QString::number(store.get_item(i).get_quantity()));
        ui->treeWidget->insertTopLevelItem(i,store_items);
    }
}

void StoreMenu::on_pushButton_3_clicked()
{
    row=ui->treeWidget->currentIndex().row();
    controller.delete_in_store(store,row);
    QTreeWidgetItem* store_items;
    ui->treeWidget->clear();
    for(int i=0;i<menu.get_size();i++)
    {
        store_items=new QTreeWidgetItem();
        store_items->setText(0,store.get_item(i).get_name());
        store_items->setText(1,QString::number(store.get_item(i).get_selling_price()));
        store_items->setText(2,QString::number(store.get_item(i).get_buying_price()));
        store_items->setText(3,QString::number(store.get_item(i).get_quantity()));
        ui->treeWidget->insertTopLevelItem(i,store_items);
    }
}

void StoreMenu::on_pushButton_4_clicked()
{
    QMessageBox::information(this,"Recipt",store.display_sellings(ui->treeWidget_2->currentIndex().row()));
}



void StoreMenu::on_pushButton_5_clicked()
{
    QStringList lst[5000];
    int size=controller.retrieve_sellings_history(store,ui->lineEdit->text(),ui->lineEdit_2->text(),lst);
    QTreeWidgetItem* history;
    qDebug()<<"here";
    ui->treeWidget_2->clear();
    for(int i=0;i<size;i++)
    {
        history=new QTreeWidgetItem();
        history->setText(0,lst[i][0]);
        history->setText(1,lst[i][2]);
        history->setText(2,lst[i][3]);
        history->setText(3,lst[i][4]);
        ui->treeWidget_2->insertTopLevelItem(i,history);
    }



}

void StoreMenu::on_treeWidget_2_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QMessageBox::information(this,"Recipt",store.display_sellings(ui->treeWidget_2->currentIndex().row()));
}


void StoreMenu::on_pushButton_6_clicked()
{
    QString promocode=QUuid::createUuid().toString();
    promocode.remove(QRegularExpression("{|}|-"));
    promocode.resize(12);
    controller.add_promocode(promocode,ui->lineEdit_3->text().toFloat()/100);
    QMessageBox::information(this,"code","Promocode is "+promocode+" with discount of "+ui->lineEdit_3->text()+"%");
}
