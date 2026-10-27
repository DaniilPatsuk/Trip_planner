#ifndef SCROLL_WIDGET_H
#define SCROLL_WIDGET_H

#include "ui_scroll_widget.h"
#include <QDialog>
#include <QtWidgets/QLineEdit>
#include <QSet>
#include <QTabWidget>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui {
class Form;
}
QT_END_NAMESPACE

class ScrollWgt : public QWidget
{
    Q_OBJECT

public:

    ScrollWgt(QJsonObject &event, QWidget *parent = 0);
    ~ScrollWgt();
private:
    QJsonObject _event;
    Ui::Form *ui;
};

#endif // SCROLL_WIDGET_H
