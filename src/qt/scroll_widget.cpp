#include "scroll_widget.h"
#include <QDebug>
ScrollWgt::ScrollWgt(QJsonObject &event, QWidget *parent)
    : QWidget(parent)
    , _event(event)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground, true);
    ui->label->setText(_event["name"].toString());
    ui->label_2->setText(_event["latitude"].toString()+", "+_event["longitude"].toString());

    ui->label_8->setText(QString::number(_event["duration"].toInt()));

    if (_event.contains("start_date")) ui->label_5->setText(_event["start_date"].toString());
    else ui->label_5->setVisible(false);

    if (_event.contains("end_date")) ui->label_9->setText(_event["end_date"].toString());
    else ui->label_9->setVisible(false);

    if (_event.contains("start_time")) ui->label_6->setText(_event["start_time"].toString());
    else ui->label_6->setVisible(false);

    if (_event.contains("end_time")) ui->label_10->setText(_event["end_time"].toString());
    else ui->label_10->setVisible(false);

}

ScrollWgt::~ScrollWgt()
{
    delete ui;
}