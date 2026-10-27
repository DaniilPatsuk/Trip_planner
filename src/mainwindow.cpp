#include "mainwindow.h"
#include "choose_date.h"
#include "city.h"
#include "event.h"
#include <QTabWidget>
// #include <fstream>
// #include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    time["date"] = QVariantMap();
    active_page = nullptr;

    //cities["city"] = QVariantMap(); вариант Данила
    //cities["city"] = QVariantList();
    ui->setupUi(this);

    // connect(ui->tabWidget, &QTabWidget::tabBarClicked, this, [this](int index)
    //         {
    //     act_city = ui->tabWidget->tabText(index);

    // });
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [this](int index)
            {
                act_city = ui->tabWidget->tabText(index);
                active_page = pages[act_city];

            });

    //обработка удаления вкладок
    {
    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this,
            [this](int index) {
                QWidget *page = ui->tabWidget->widget(index);

                QVariantMap map_cities = cities["city"].toMap();
                map_cities.remove(ui->tabWidget->tabText(index));
                cities["city"] = map_cities;
                pages.remove(ui->tabWidget->tabText(index));
                //удаляем вкладку из tabWidget, но указатель остается
                ui->tabWidget->removeTab(index);
                //удаляем указатель на стриницу
                if (page) page->deleteLater();

                updateCloseButtons();
            });

    connect(ui->tabWidget, &QTabWidget::currentChanged, this,
            [this](){updateCloseButtons(); });
    }

}
void MainWindow::updateCloseButtons() {
    ui->tabWidget->setTabsClosable(ui->tabWidget->count() > 1);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::choose_date()
{
    Date ch_date(time, ui->label, ui->label_3, this);
    ch_date.exec();

}

void MainWindow::add_city()
{

    City en_city(cities, cityList, ui->tabWidget, pages, this);
    en_city.exec();
    auto a = en_city.getInnerlayOut();
    if (a) active_page = a;
}



void MainWindow::add_event()
{
    if (active_page == nullptr) {
        QMessageBox::warning(this, "Ошибка", "Добавь город");
        return;
    }
    Event en_event(active_page, cities, act_city, this);
    en_event.exec();
}
#include <QJsonDocument>
#include <QFile>

void MainWindow::start()
{
    //cp_plan["city"] = cities["city"];
    // QJson::Serializer serializer;
    // QByteArray json = serializer.serialize(people);

    //     std::ofstream ofs1("C:/Users/andre/Documents/TripPlanner/trip.json");
    //     if (!ofs1.is_open()) {
    //         std::cout << "Не удалось открыть файл для записи:" << std::endl;
    //         return;
    //     }
    //     std::cout << "file open" << std::endl;
    //     ofs1 << std::setw(4) << cp_plan;
    //     ofs1.close();
    //     city.clear();
    QVariantMap merged = cities;
    for (auto it = time.constBegin(); it != time.constEnd(); ++it) {
        merged.insert(it.key(), it.value());
    }
    QJsonObject obj = QJsonObject::fromVariantMap(merged);
    // QJsonObject obj2 = QJsonObject::fromVariantMap(time);
    // obj2.unite(obj1);
    QJsonDocument doc(obj);

    QFile file("C:/Users/andre/Documents/TripPlanner/trip.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qWarning() << "Не открыть файл:" << file.errorString();
        return;
    }

    file.write(doc.toJson(QJsonDocument::Indented));

}