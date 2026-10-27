#ifndef CHOOSE_DATE_H
#define CHOOSE_DATE_H

#include <QDialog>
#include "ui_choose_date.h"
#include <QDateEdit>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE


class Date : public QDialog
{
    Q_OBJECT

public:
    QDateEdit* dateEdit = 0;
    QDateEdit* dateEdit_2 = 0;
    Date(QVariantMap& time, QLabel *label, QLabel *label2, QWidget *parent = 0);
    ~Date() override;

private:
    QLabel *cp_l;
    QLabel *cp_l2;
    QVariantMap& cp_time;
    Ui::Dialog *ui;
public slots:
    void accept() override;
};

#endif // CHOOSE_DATE_H
