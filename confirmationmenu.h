#ifndef CONFIRMATIONMENU_H
#define CONFIRMATIONMENU_H

#include <QDialog>

namespace Ui {
class ConfirmationMenu;
}

class ConfirmationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmationMenu(QWidget *parent = nullptr);
    ~ConfirmationMenu();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_3_editingFinished();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_clicked(bool checked);

private:
    Ui::ConfirmationMenu *ui;
};

#endif // CONFIRMATIONMENU_H
