#include "event.h"
#include "scroll_widget.h"
#include <QDebug>

Event::Event(QVBoxLayout* activePage, QVariantMap &cities, QString &act_city, QWidget *parent)
    : QDialog(parent)
    , actPage(activePage)
    , cp_cities(cities)
    , cp_actCity(act_city)
    , ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    ui->timeEdit_2->setVisible(false);
    ui->dateEdit_2->setVisible(false);
    ui->line->setVisible(false);
    ui->line_2->setVisible(false);

    QObject::connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Event::onComboBoxIndexChanged);
}

Event::~Event()
{
    delete ui;
}

void Event::accept()
{
    QString qname = ui->lineEdit->text();
    if (qname.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполни название события");
        return;
    }
    else {
        obj["name"] = qname;
        //QString qaddress = ui->textEdit->toPlainText();
        QString adress = ui->lineEdit_2->text();
        QStringList lat_long = adress.split(QRegExp(", "));
        if (lat_long.length() != 2) {
            QMessageBox::warning(this, "Ошибка", "Заполни адрес");
            return;
        }
        else {
            QString latitude = lat_long[0];
            QString longitude = lat_long[1];
            obj["latitude"] = latitude;
            obj["longitude"] = longitude;
            std::string qtype = eventType[ui->comboBox->currentIndex()];
            //qDebug() << QString::fromStdString(qtype);
            obj["type"] = QString::fromStdString(qtype);
            QTime qstime = ui->timeEdit->time();
            //QTime qftime;
            if (EditsOnForm & EventEdits::SecondTimeEdit) {
                QTime qftime = ui->timeEdit_2->time();
                if (qstime < qftime) {
                    obj["start_time"] = qstime.toString("HH:mm");
                    obj["end_time"] = qftime.toString("HH:mm");
                }
                else {
                    QMessageBox::warning(this, "Ошибка", "Исправь время");
                    return;
                }
            }
            else {
                obj["start_time"] = qstime.toString("HH:mm");
            }
                QDate qsdate;
                qsdate = ui->dateEdit->date();
                if (EditsOnForm & EventEdits::SecondDateEdit) {
                    QDate qfdate = ui->dateEdit_2->date();
                    if (qsdate < qfdate) {
                        obj["start_date"] = qsdate.toString("yyyy.MM.dd");
                        obj["end_date"] = qfdate.toString("yyyy.MM.dd");
                    }
                    else {
                        QMessageBox::warning(this, "Ошибка", "Исправь дату");
                        return;
                    }
                }
                else if (!(EditsOnForm & EventEdits::FirstDateEdit)) {
                    qDebug() << "First date is visible";
                    obj["start_date"] = qsdate.toString("yyyy.MM.dd");
                }
                    qDebug() << "First date isn't visible";
                    int qduration = ui->spinBox->value()*60 + ui->spinBox_2->value();
                    if(qduration == 0)
                    {
                        QMessageBox::warning(this, "Ошибка", "Исправь длительность");
                        return;
                    }
                    else obj["duration"] = qduration;


        }
    }
    ScrollWgt *scroll_widget = new ScrollWgt(obj);
    scroll_widget->setFixedWidth(790);
    scroll_widget->setFixedHeight(150);
    actPage->insertWidget(0, scroll_widget);



    qDebug() << "good 1";
    QVariantMap list_cities = cp_cities["city"].toMap();
    QVariantMap typesEvents = list_cities[cp_actCity].toMap();
    qDebug() << "good 2";
    if (obj["type"] == "Habit") {
        QVariantList some_events = typesEvents["habitations"].toList();
        some_events.append(obj);
        typesEvents["habitations"] = some_events;
    }
    else {
        QVariantList some_events = typesEvents["activities"].toList();
        some_events.append(obj);
        typesEvents["activities"] = some_events;
    }
    qDebug() << "good 3";
    list_cities[cp_actCity] = typesEvents;
    cp_cities["city"] = list_cities;


    //scroll_widget->setMinimumSize(750, 150); // Или setFixedSize(300, 200);





    QDialog::accept();
}

void Event::onComboBoxIndexChanged(int index)
{


    EditsOnForm = 7 & index;
    ui->timeEdit_2->setVisible(EditsOnForm & EventEdits::SecondTimeEdit);
    ui->dateEdit_2->setVisible(EditsOnForm & EventEdits::SecondDateEdit);
    ui->dateEdit->setVisible(!(EditsOnForm & EventEdits::FirstDateEdit));
    ui->line->setVisible(EditsOnForm & EventEdits::SecondTimeEdit);
    ui->line_2->setVisible(EditsOnForm & EventEdits::SecondDateEdit);



}
