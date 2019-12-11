#include "confirmationmenu.h"
#include "ui_confirmationmenu.h"
#include "global.h"

ConfirmationMenu::ConfirmationMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmationMenu)
{
    ui->setupUi(this);
    ui->label_3->setText(QVariant(cart.get_total_price()).toString());
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
