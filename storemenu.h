#ifndef STOREMENU_H
#define STOREMENU_H
#include <QListWidgetItem>
#include <QDialog>

namespace Ui {
class StoreMenu;
}

class StoreMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StoreMenu(QWidget *parent = nullptr);
    ~StoreMenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_5_clicked();

private:
    Ui::StoreMenu *ui;
};

#endif // STOREMENU_H
