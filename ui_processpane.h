/********************************************************************************
** Form generated from reading UI file 'processpane.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSPANE_H
#define UI_PROCESSPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessPane
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QWidget *backgroundwidget;
    QProgressBar *progressBar;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *ProcessPane)
    {
        if (ProcessPane->objectName().isEmpty())
            ProcessPane->setObjectName(QString::fromUtf8("ProcessPane"));
        ProcessPane->resize(1058, 693);
        ProcessPane->setMinimumSize(QSize(30, 30));
        ProcessPane->setMaximumSize(QSize(16777215, 16777215));
        ProcessPane->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        gridLayout = new QGridLayout(ProcessPane);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 244, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(326, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        widget = new QWidget(ProcessPane);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(400, 200));
        widget->setMaximumSize(QSize(400, 200));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255,0);"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        backgroundwidget = new QWidget(widget);
        backgroundwidget->setObjectName(QString::fromUtf8("backgroundwidget"));
        backgroundwidget->setStyleSheet(QString::fromUtf8("#backgroundwidget\n"
"{\n"
"	border: 3px solid \"#62d2a2\";\n"
"	border-radius:5px;\n"
"    font:bold 24px;\n"
"	background-color: rgba(0,0,0,80);\n"
"}"));
        progressBar = new QProgressBar(backgroundwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(40, 30, 301, 23));
        progressBar->setStyleSheet(QString::fromUtf8("\n"
"QProgressBar\n"
"{\n"
"	border-radius:5px;\n"
"	background-color: rgba(255,255,255,10);\n"
"\n"
"}\n"
"QProgressBar::chunk\n"
"{\n"
"	border-radius:5px;\n"
"	background-color:#62d2a2;\n"
"}\n"
""));
        progressBar->setMaximum(0);
        progressBar->setValue(-1);
        progressBar->setTextVisible(false);
        label = new QLabel(backgroundwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 70, 301, 31));
        label->setStyleSheet(QString::fromUtf8("color:#62d2a2;\n"
"font:bold 18px;"));

        gridLayout_2->addWidget(backgroundwidget, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(326, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 243, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(ProcessPane);

        QMetaObject::connectSlotsByName(ProcessPane);
    } // setupUi

    void retranslateUi(QWidget *ProcessPane)
    {
        ProcessPane->setWindowTitle(QCoreApplication::translate("ProcessPane", "Form", nullptr));
        label->setText(QCoreApplication::translate("ProcessPane", "\345\257\274\345\205\245\346\226\207\344\273\266\344\270\255\357\274\214\350\257\267\347\250\215\347\255\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProcessPane: public Ui_ProcessPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSPANE_H
