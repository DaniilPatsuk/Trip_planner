#include "city.h"
#include <QScrollArea>
#include <QDebug>

City::City(QVariantMap &cities, QSet<QString> &cityList, QTabWidget *tabs,  QHash<QString,  QVBoxLayout*> &pages, QWidget *parent)
    : QDialog(parent)
    , citiesSet(cityList)
    , cp_cities(cities)
    , cp_tabs(tabs)
    , cp_pages(pages)
    , ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    a = nullptr;
    lineEdit = ui->lineEdit;
}

City::~City()
{
    delete ui;
}

void City::accept()
{
    QString text = lineEdit->text();

    if (text.isEmpty()) {
        return;
    }
    else {
        if (!citiesSet.contains(text))
        {
            int len_set = citiesSet.size();
            citiesSet.insert(text);
            if (len_set != citiesSet.size()) {
                QWidget *newPage = new QWidget();
                QVBoxLayout *pageLayout = new QVBoxLayout(newPage);
                pageLayout->setContentsMargins(0, 0, 0, 0);
                QScrollArea *scrollarea = new QScrollArea();
                scrollarea->setWidgetResizable(true);
                pageLayout->addWidget(scrollarea);
                QWidget *scrollContent = new QWidget();
                QVBoxLayout *contentLayout = new QVBoxLayout(scrollContent);
                contentLayout->addStretch();
                scrollarea->setWidget(scrollContent);
                cp_tabs->addTab(newPage, text);
                cp_tabs->setTabsClosable(cp_tabs->count() > 1);
                cp_tabs->setCurrentWidget(newPage);
                a = contentLayout;
                cp_pages[text] = contentLayout;
            }
            //вариант данила
            // QVariantMap newCity;
            // QVariantMap act_hab;
            // act_hab["activities"] = QVariantList();
            // act_hab["habitations"] = QVariantList();
            // newCity[text] = act_hab;
            // QVariantList list = cp_cities["city"].toList();  // достаем список
            // list.append(newCity);
            // // меняем копию
            // cp_cities["city"] = list;

            QVariantMap act_hab;
            act_hab["activities"] = QVariantList();
            act_hab["habitations"] = QVariantList();
            QVariantMap list = cp_cities["city"].toMap();
            list[text] = act_hab;
            cp_cities["city"] = list;
        }
    }



    QDialog::accept();
}
//получение ууказателя на активный компановщик для вставки события
QVBoxLayout* City::getInnerlayOut()
{
    if (a == nullptr) return 0;
    return a;
}


