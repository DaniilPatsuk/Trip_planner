
#include "mainwindow.h"
#include <QApplication>
#include <vector>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>



int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    QApplication a(argc, argv);

    //nlohmann::json plan;
    MainWindow w;
    w.show();
    return QApplication::exec();






}
