#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "global.h"


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/loginwallpaper/Info Wallpapers abstract wallpaper hd.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

}

login::~login()
{


    delete ui;

}

void login::on_pushButton_clicked()
{

    user=controller.login(ui->lineEdit->text(),ui->lineEdit_2->text());

   if(user->isLoggedin())
    {
        close();
    }
    else
    {
        Dialog di;
        di.exec();
    }

}
