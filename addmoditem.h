#ifndef ADDMODITEM_H
#define ADDMODITEM_H

#include <QDialog>

namespace Ui {
class AddModItem;
}

class AddModItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddModItem(QWidget *parent = nullptr);
    ~AddModItem();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddModItem *ui;
};

#endif // ADDMODITEM_H
