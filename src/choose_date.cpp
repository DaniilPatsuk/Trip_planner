#include "choose_date.h"


Date::Date(QVariantMap& time, QLabel *label, QLabel *label2, QWidget *parent)
    : QDialog(parent)
    , cp_l(label)
    , cp_l2(label2)
    , cp_time(time)
    , ui(new Ui::Dialog)

{

    ui->setupUi(this);
    dateEdit = ui->dateEdit;
    dateEdit_2 = ui->dateEdit_2;
}

Date::~Date()
{
    delete ui;
}

void Date::accept()
{
    QDate start_date = dateEdit->date();
    QDate finish_date = dateEdit_2->date();
    QString sDate = start_date.toString("yyyy-MM-dd");
    QString fDate = finish_date.toString("yyyy-MM-dd");
    cp_l->setText(sDate);
    cp_l2->setText(fDate);
    // std::cout << sDate << std::endl;
    // std::cout << fDate << std::endl;
    // cp_plan["date"]["start_date"] = sDate;
    // cp_plan["date"]["end_date"] = fDate;
    QVariantMap map = cp_time["date"].toMap();
    map["start_date"] = sDate;
    map["end_date"] = fDate;
    cp_time["date"] = map;
    QDialog::accept();


}