#include "confirmationmenu.h"
#include "ui_confirmationmenu.h"
#include "global.h"

ConfirmationMenu::ConfirmationMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmationMenu)
{
    ui->setupUi(this);
    ui->label_3->setText(QVariant(cart.get_total_price()).toString());
    ui->label_7->hide();
    ui->label_8->hide();
    if(customer.get_phone()=="")
    {
        ui->radioButton->setCheckable(false);
        ui->radioButton_2->setCheckable(false);
        ui->lineEdit_3->setReadOnly(true);
    }
    else
    {
        ui->radioButton->setCheckable(true);
        ui->radioButton_2->setCheckable(true);
        ui->lineEdit_3->setReadOnly(false);
    }
    ui->radioButton_2->setChecked(true);

}

ConfirmationMenu::~ConfirmationMenu()
{
    delete ui;
}

void ConfirmationMenu::on_pushButton_clicked()
{
    paid=ui->lineEdit->text().toFloat();
    if(ui->radioButton->isChecked())
    {
        delivery=1;
        delivery_fee=ui->lineEdit_3->text().toFloat();
    }
    else
    {
        delivery=0;
        delivery_fee=0;
    }
    close();
}

void ConfirmationMenu::on_lineEdit_3_editingFinished()
{

}

void ConfirmationMenu::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->label_3->setText(QVariant((cart.get_total_price()+ui->lineEdit_3->text().toFloat())).toString());
}

void ConfirmationMenu::on_pushButton_3_clicked()
{
    float discount=controller.check_promocode(ui->lineEdit_2->text());
    qDebug()<<discount;
    int discount_percentage=discount*100;
    if(discount!=0)
    {
        ui->label_8->hide();
        ui->label_7->show();
        ui->label_7->setText("Promocode applied successfuly "+QVariant(discount_percentage).toString()+"% discount !");
    }
    else
    {
        ui->label_7->hide();
        ui->label_8->show();

    }
}
