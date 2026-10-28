/********************************************************************************
** Form generated from reading UI file 'event.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENT_H
#define UI_EVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTimeEdit *timeEdit_2;
    QDateEdit *dateEdit_2;
    QFrame *line;
    QFrame *line_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName(QString::fromUtf8("Dialog2"));
        Dialog2->resize(420, 380);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog2->sizePolicy().hasHeightForWidth());
        Dialog2->setSizePolicy(sizePolicy);
        Dialog2->setMinimumSize(QSize(420, 380));
        Dialog2->setMaximumSize(QSize(420, 380));
        buttonBox = new QDialogButtonBox(Dialog2);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 340, 193, 29));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(Dialog2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 40, 390, 25));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        comboBox = new QComboBox(Dialog2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(69, 150, 330, 25));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMaximumSize(QSize(330, 25));
        label = new QLabel(Dialog2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 69, 20));
        label_2 = new QLabel(Dialog2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 121, 20));
        label_3 = new QLabel(Dialog2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 150, 69, 20));
        timeEdit = new QTimeEdit(Dialog2);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(90, 200, 111, 24));
        dateEdit = new QDateEdit(Dialog2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(90, 240, 111, 24));
        label_4 = new QLabel(Dialog2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 240, 69, 20));
        label_5 = new QLabel(Dialog2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 200, 69, 20));
        label_6 = new QLabel(Dialog2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 290, 111, 20));
        timeEdit_2 = new QTimeEdit(Dialog2);
        timeEdit_2->setObjectName(QString::fromUtf8("timeEdit_2"));
        timeEdit_2->setGeometry(QRect(240, 200, 118, 24));
        dateEdit_2 = new QDateEdit(Dialog2);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(240, 240, 121, 24));
        line = new QFrame(Dialog2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(210, 204, 21, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Dialog2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(210, 251, 21, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        spinBox = new QSpinBox(Dialog2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(130, 290, 44, 24));
        spinBox_2 = new QSpinBox(Dialog2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(200, 290, 44, 24));
        spinBox_3 = new QSpinBox(Dialog2);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(290, 290, 44, 24));
        label_7 = new QLabel(Dialog2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(180, 290, 16, 20));
        label_8 = new QLabel(Dialog2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(250, 290, 41, 20));
        label_9 = new QLabel(Dialog2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(340, 290, 69, 20));
        lineEdit_2 = new QLineEdit(Dialog2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 100, 391, 28));

        retranslateUi(Dialog2);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog2, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog2, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QCoreApplication::translate("Dialog2", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Dialog2", "\321\204\320\270\320\272\321\201\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\265 \320\277\320\276 \320\264\320\260\321\202\320\265 \320\270 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Dialog2", "\321\204\320\270\320\272\321\201\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\265 \320\277\320\276 \320\264\320\260\321\202\320\265", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Dialog2", "\321\204\320\270\320\272\321\201\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\265 \320\277\320\276 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Dialog2", "\320\275\320\265\321\204\320\270\320\272\321\201\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\265", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Dialog2", "\321\200\320\265\320\263\321\203\320\273\321\217\321\200\320\275\320\276\320\265", nullptr));

        label->setText(QCoreApplication::translate("Dialog2", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog2", "\320\250\320\270\321\200\320\276\321\202\320\260 \320\270 \320\264\320\276\320\273\320\263\320\276\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog2", "\320\242\320\270\320\277:", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog2", "\320\224\320\260\321\202\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog2", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog2", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog2", "\321\207.", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog2", "\320\274\320\270\320\275.", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog2", "\321\201\320\265\320\272.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENT_H
