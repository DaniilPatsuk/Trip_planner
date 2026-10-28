#ifndef EVENT_H
#define EVENT_H

#include <QDialog>
#include "ui_event.h"
#include <QComboBox>
#include <map>
#include <QMessageBox>
#include <QJsonObject>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui
{
class Dialog2;
}
QT_END_NAMESPACE
 
class Event : public QDialog
{
    Q_OBJECT
public:
    Event(QVBoxLayout* activePage, QVariantMap &cities, QString &act_city, QWidget *parent = 0);
    ~Event();
private:
    QVBoxLayout* actPage;
    QVariantMap& cp_cities;
    QString cp_actCity;
    QJsonObject obj;
    std::map<int, std::string> eventType = {
        {0, "AllFix"},
        {1, "DayFix"},
        {2, "TimeFix"},
        {3, "NoneFix"},
        {4, "Habit"}
    };

    int EditsOnForm;
    enum EventEdits {
        SecondTimeEdit = 1,
        FirstDateEdit = 4,
        SecondDateEdit = 2,
    };

    Ui::Dialog2 *ui;
public slots:
    void onComboBoxIndexChanged(int index);
    void accept() override;
};

#endif // EVENT_H
