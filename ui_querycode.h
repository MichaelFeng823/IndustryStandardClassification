/********************************************************************************
** Form generated from reading UI file 'querycode.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYCODE_H
#define UI_QUERYCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueryCodeClass
{
public:
    QTreeWidget *treeWidget;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_Code;
    QLabel *label_2;

    void setupUi(QWidget *QueryCodeClass)
    {
        if (QueryCodeClass->objectName().isEmpty())
            QueryCodeClass->setObjectName(QString::fromUtf8("QueryCodeClass"));
        QueryCodeClass->resize(600, 400);
        treeWidget = new QTreeWidget(QueryCodeClass);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(20, 100, 561, 291));
        treeWidget->header()->setVisible(false);
        treeWidget->header()->setStretchLastSection(true);
        lineEdit = new QLineEdit(QueryCodeClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 50, 113, 20));
        label = new QLabel(QueryCodeClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 50, 54, 12));
        lineEdit_Code = new QLineEdit(QueryCodeClass);
        lineEdit_Code->setObjectName(QString::fromUtf8("lineEdit_Code"));
        lineEdit_Code->setEnabled(true);
        lineEdit_Code->setGeometry(QRect(360, 50, 113, 20));
        label_2 = new QLabel(QueryCodeClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 54, 12));

        retranslateUi(QueryCodeClass);

        QMetaObject::connectSlotsByName(QueryCodeClass);
    } // setupUi

    void retranslateUi(QWidget *QueryCodeClass)
    {
        QueryCodeClass->setWindowTitle(QCoreApplication::translate("QueryCodeClass", "QueryCode", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("QueryCodeClass", "1", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("QueryCodeClass", "22", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("QueryCodeClass", "2", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("QueryCodeClass", "3", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem3->child(0);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("QueryCodeClass", "31", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem3->child(1);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("QueryCodeClass", "32", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("QueryCodeClass", "4", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem2->child(2);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("QueryCodeClass", "5", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem2->child(3);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("QueryCodeClass", "6", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem2->child(4);
        ___qtreewidgetitem9->setText(0, QCoreApplication::translate("QueryCodeClass", "33", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem10->setText(0, QCoreApplication::translate("QueryCodeClass", "3", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("QueryCodeClass", "\345\275\223\345\211\215\344\273\243\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("QueryCodeClass", "\350\276\223\345\205\245\346\237\245\350\257\242\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QueryCodeClass: public Ui_QueryCodeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYCODE_H
