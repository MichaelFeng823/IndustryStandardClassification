/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QWidget *backgroundwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox_2;
    QPushButton *ImportRootButton;
    QPushButton *ImportSonButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QFrame *line;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1058, 693);
        MainWindow->setStyleSheet(QString::fromUtf8("#MainWindow\n"
"{\n"
"	background-color:\"#1fab89\";\n"
"}"));
        gridLayout = new QGridLayout(MainWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        backgroundwidget = new QWidget(MainWindow);
        backgroundwidget->setObjectName(QString::fromUtf8("backgroundwidget"));
        backgroundwidget->setStyleSheet(QString::fromUtf8("#backgroundwidget{\n"
"	border-image: url(:/pic/image/1.jpg);\n"
"	border-radius:15px;\n"
"}"));
        gridLayout_2 = new QGridLayout(backgroundwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(15);
        gridLayout_2->setContentsMargins(15, 15, 15, 15);
        groupBox = new QGroupBox(backgroundwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	border: 1px solid \"#62d2a2\";\n"
"	border-radius:5px;\n"
"	margin-top:2ex;\n"
"	font:bold 24px;\n"
"	background-color: rgba(255,255,255,50);\n"
"}\n"
" \n"
"QGroupBox::title\n"
"{\n"
"	color: \"#9df3c4\";\n"
"	subcontrol-origin:margin;\n"
"	subcontrol-position:top center;	\n"
"	padding:0 3px;\n"
"}\n"
"QTreeWidget\n"
"{\n"
"	background-color: rgba(255,255,255,0);\n"
"	border:none;\n"
"}\n"
"QScrollBar:vertical{\n"
"	background-color:rgba(255,255,255,0);\n"
"	border:none;\n"
"}\n"
"/*\346\273\232\345\212\250\346\235\241\344\270\212\342\276\257\345\222\214\344\270\213\342\276\257\345\214\272\345\237\237\346\240\267\345\274\217*/\n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical\n"
"{\n"
"	background-color:rgba(255,255,255,30);\n"
"	border:none\n"
"}\n"
"/*\345\220\221\344\270\212\347\256\255\345\244\264\346\240\267\345\274\217*/\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"	background:rgba(255,255,255,0)\n"
"}\n"
"/*\345\220\221\344\270\213\347\256\255\345\244\264\346\240\267\345"
                        "\274\217*/\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"	background:rgba(255,255,255,0)\n"
"}\n"
"\n"
""));
        groupBox->setAlignment(Qt::AlignCenter);
        treeWidget = new QTreeWidget(groupBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(20, 90, 461, 531));
        treeWidget->setStyleSheet(QString::fromUtf8(""));
        treeWidget->header()->setVisible(false);
        treeWidget->header()->setStretchLastSection(true);

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(backgroundwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	border: 1px solid \"#62d2a2\";\n"
"	border-radius:5px;\n"
"	margin-top:2ex;\n"
"    font:bold 24px;\n"
"	background-color: rgba(255,255,255,50);\n"
"}\n"
" \n"
"QGroupBox::title\n"
"{\n"
"	color: \"#9df3c4\";\n"
"	subcontrol-origin:margin;\n"
"	subcontrol-position:top center;	\n"
"	padding:0 3px;\n"
"	\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	color:rgb(0,0,0);\n"
"	background-color: \"#9df3c4\";\n"
"	border:3px solid  \"#1fab89\";\n"
"	font:bold 14px;\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	color:rgb(0,0,0);\n"
"	background-color: \"#1fab89\";\n"
"	border:3px solid  \"#1fab89\";\n"
"	font:bold 14px;\n"
"	border-radius:5px;\n"
"}\n"
"QLineEdit\n"
"{\n"
"	color:rgb(0,0,0);\n"
"	background-color: \"#9df3c4\";\n"
"	border:3px solid  \"#1fab89\";\n"
"	font:bold 14px;\n"
"	border-radius:5px;\n"
"}\n"
""));
        groupBox_2->setAlignment(Qt::AlignCenter);
        ImportRootButton = new QPushButton(groupBox_2);
        ImportRootButton->setObjectName(QString::fromUtf8("ImportRootButton"));
        ImportRootButton->setGeometry(QRect(80, 40, 140, 30));
        ImportRootButton->setMinimumSize(QSize(140, 30));
        ImportRootButton->setMaximumSize(QSize(140, 30));
        ImportSonButton = new QPushButton(groupBox_2);
        ImportSonButton->setObjectName(QString::fromUtf8("ImportSonButton"));
        ImportSonButton->setGeometry(QRect(300, 40, 140, 30));
        ImportSonButton->setMinimumSize(QSize(140, 30));
        ImportSonButton->setMaximumSize(QSize(140, 30));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 100, 251, 41));
        lineEdit->setMinimumSize(QSize(251, 41));
        lineEdit->setMaximumSize(QSize(251, 41));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(350, 100, 81, 41));
        pushButton_3->setMinimumSize(QSize(81, 41));
        pushButton_3->setMaximumSize(QSize(81, 41));
        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 80, 481, 1));
        line->setStyleSheet(QString::fromUtf8("background-color: \"#62d2a2\";"));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(0);
        line->setFrameShape(QFrame::HLine);

        gridLayout_2->addWidget(groupBox_2, 0, 1, 1, 1);


        gridLayout->addWidget(backgroundwidget, 0, 0, 1, 1);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\261\202\347\272\247\345\217\257\350\247\206\345\214\226", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\345\214\272", nullptr));
        ImportRootButton->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\344\270\200\347\272\247\347\233\256\345\275\225", nullptr));
        ImportSonButton->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\345\255\220\347\272\247\347\233\256\345\275\225", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\243\200\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
