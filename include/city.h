#ifndef CITY_H
#define CITY_H

#include <QDialog>
#include <QtWidgets/QLineEdit>
#include "ui_city.h"
#include <QSet>
#include <QTabWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog1;
}
QT_END_NAMESPACE

class City : public QDialog
{
    Q_OBJECT

public:
    QVBoxLayout* getInnerlayOut();
    QLineEdit *lineEdit = nullptr;
    City(QVariantMap &cities, QSet<QString> &cityList, QTabWidget *tabs,  QHash<QString,  QVBoxLayout*>& pages, QWidget *parent = 0);
    ~City();
private:
    QSet<QString> &citiesSet;
    QVariantMap& cp_cities;
    QTabWidget *cp_tabs;
    QVBoxLayout* a;
     QHash<QString,  QVBoxLayout*> &cp_pages;
    Ui::Dialog1 *ui;


public slots:
    void accept() override;

};

#endif // CITY_H
