#ifndef STOREMENU_H
#define STOREMENU_H
#include <QListWidgetItem>
#include <QDialog>
#include <QTreeWidgetItem>

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



    void on_pushButton_5_clicked();

    void on_treeWidget_2_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_6_clicked();

private:
    Ui::StoreMenu *ui;
};

#endif // STOREMENU_H
