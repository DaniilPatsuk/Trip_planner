#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_trip_planner.h"
#include <QJsonArray>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
 
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void addCity(QString &nameCity);


private:
    QVariantMap cities;
    QSet<QString> cityList;
    //QString activeCity;
    QVariantMap time;
    QString act_city;
    QVBoxLayout* active_page;
    Ui::MainWindow *ui;

    QHash<QString,  QVBoxLayout*> pages;


public slots:
    void choose_date();
    void add_city();
    void updateCloseButtons();
    void add_event();
    void start();

};
#endif // MAINWINDOW_H
