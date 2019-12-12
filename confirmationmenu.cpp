#include "confirmationmenu.h"
#include "ui_confirmationmenu.h"
#include "global.h"
QString promocode;
ConfirmationMenu::ConfirmationMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmationMenu)
{
    ui->setupUi(this);
    ui->label_3->setText(QString::number(cart.get_total_price()));
    ui->label_7->hide();
    ui->label_8->hide();
    confirme=0;
    QPixmap bkgnd(":/new/prefix4/images.jpg");
        QSize size;
        size.setWidth(1920);
        size.setHeight(1080);
        bkgnd = bkgnd.scaled(size, Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
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
    ui->lineEdit_3->setReadOnly(true);

}

ConfirmationMenu::~ConfirmationMenu()
{
    delete ui;
}

void ConfirmationMenu::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="")
    {
        paid=0;
    }
    else
    {
        paid=ui->lineEdit->text().toFloat();
    }

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
    controller.remove_promocode(promocode);
    confirme=1;
    close();
}

void ConfirmationMenu::on_lineEdit_3_editingFinished()
{

}

void ConfirmationMenu::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->label_3->setText(QString::number((cart.get_total_price()*(1-promocode_discount)+ui->lineEdit_3->text().toFloat())));
}

void ConfirmationMenu::on_pushButton_3_clicked()
{
    promocode_discount=controller.check_promocode(ui->lineEdit_2->text());

    promocode=ui->lineEdit_2->text();
    int discount_percentage=promocode_discount*100;
    if(promocode_discount!=0)
    {
        ui->label_8->hide();
        ui->label_7->show();
        ui->label_7->setText("Promocode applied successfuly "+QString::number(discount_percentage)+"% discount !");
        ui->label_3->setText(QString::number((cart.get_total_price()*(1-promocode_discount)+ui->lineEdit_3->text().toFloat())));
    }
    else
    {
        ui->label_7->hide();
        ui->label_8->show();
        ui->label_3->setText(QString::number((cart.get_total_price()*(1-promocode_discount)+ui->lineEdit_3->text().toFloat())));

    }
}

void ConfirmationMenu::on_radioButton_2_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit_3->setReadOnly(true);
        ui->lineEdit_3->clear();
    }
}

void ConfirmationMenu::on_radioButton_clicked(bool checked)
{
    if(checked)
    {
        ui->lineEdit_3->setReadOnly(false);

    }
}

void ConfirmationMenu::on_pushButton_2_clicked()
{
    close();
}
