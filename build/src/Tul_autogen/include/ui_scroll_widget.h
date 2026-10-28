/********************************************************************************
** Form generated from reading UI file 'scroll_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCROLL_WIDGET_H
#define UI_SCROLL_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(600, 150);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setMinimumSize(QSize(600, 150));
        Form->setMaximumSize(QSize(620, 150));
        Form->setStyleSheet(QString::fromUtf8("ScrollWgt {\n"
"    border: 2px solid red;\n"
"    border-radius: 5px; /* \320\225\321\201\320\273\320\270 \321\205\320\276\321\202\320\270\321\202\320\265 \321\201\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"}"));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 191, 21));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 40, 191, 16));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 70, 47, 14));
        label_4 = new QLabel(Form);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 100, 47, 14));
        label_5 = new QLabel(Form);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 70, 81, 16));
        label_6 = new QLabel(Form);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(110, 100, 91, 16));
        label_7 = new QLabel(Form);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(330, 80, 101, 16));
        label_8 = new QLabel(Form);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(440, 80, 71, 16));
        label_9 = new QLabel(Form);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(210, 70, 81, 16));
        label_10 = new QLabel(Form);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(210, 100, 81, 16));
        label_11 = new QLabel(Form);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(500, 80, 47, 14));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "\320\224\320\260\321\202\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("Form", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214:", nullptr));
        label_8->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("Form", "\320\274\320\270\320\275.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCROLL_WIDGET_H
