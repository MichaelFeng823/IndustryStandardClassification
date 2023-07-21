#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QThread>
#include "excelprocessing.h"
#include <QSqlDatabase>
#include <QMap>
#include <QTreeWidgetItem>
#include "Public/PublicStruct.h"
#include "processpane.h"
#include <QVariant>
///****************************************************************************
/// @author  : MichaelFeng
/// @date    : 2023/07/04
/// @file    : mainwindow.h
/// @brief   : 主窗口界面
///----------------------------------------------------------------------------
///                           Change History
///----------------------------------------------------------------------------
///
///****************************************************************************
namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    struct NodeMap{
        QString CodeId;
        QString ComponentName;
    };

    void initExcelThread();          //初始化excel子线程
    void initDB();                   //初始化数据库
    void initConnect();              //初始化连接
    void initRootData();             //初始化根节点数据
    void initSonData();              //初始化子节点数据
    void bindSonToRoot();            //绑定子节点到父节点上
    void bindSonToSon();             //绑定次子节点到子节点上
    void initTree();                 //初始化树
    //void initRode(QTreeWidgetItem * item,int & iterations, QString key, QVector<QMap<QString,QVector<NodeMap*>>> mapvector);            //初始化节点
    void initFirstLevelRode(QTreeWidgetItem * item, QString key);             //初始化一级节点
    void initSecondLevelRode(QTreeWidgetItem * item, QString key);            //初始化二级节点
    void initThridLevelRode(QTreeWidgetItem * item, QString key);             //初始化三级节点
    void initFourthLevelRode(QTreeWidgetItem * item, QString key);            //初始化四级节点
    void showAllNode();                                                       //显示所有节点
    void changeSwit(QTreeWidgetItem * item);                                  //改变判断
    void searchItem(QTreeWidgetItem * item, QString keywords);                //对当前节点进行遍历查找并且对遍历的节点进行显示
    void showSon(QTreeWidgetItem * item);                                     //显示子节点
    void showParent(QTreeWidgetItem * item);                                  //显示父节点
    bool saveRootData(QVector<RootLevel>);                                    //保存根节点数据
    bool saveSonData(QVector<SonLevel>);                                      //保存子节点数据
    void startExcelThread();                                                  //开启Excel线程
    void openProcessPane();                                                   //开启processpane窗口
    void closeProcessPane();                                                  //关闭processpane窗口
    void updateData();                                                        //刷新数据
    QString checkInputIsCodeId(QString text);                                 //检测输入内容是否为CodeId
    bool isAllContains(QString text,QString subtext);                         //是否全包含
    void clearMapLength(QMap<QString,QVector<NodeMap*>> m_maplength);         //清除MAP内容的残留指针对象  
public slots:
    void onImportRootButtonClicked();
    void onImportSonButtonClicked();
    void onItemDoubleClicked(QTreeWidgetItem *item,int column);
    void on_inputQueryNode();                            //响应输入查询
    void onExcelImportRootFinished(QVariant);            //当excel导入完成
    void onExcelImportSonFinished(QVariant);             //当excel导入完成


signals:


private:
    QThread * thread;                         //子线程指针
    ProcessPane * processpane = nullptr;                //进度提示窗口指针
    ExcelProcessing * excelThread;            //excel执行线程
    QSqlDatabase coon;
    bool hasConnected = false;                //数据库是否已连接
    bool swit;
    QVector<RootLevel> m_rootList;            //根节点list
    QVector<SonLevel> m_sonList;              //子节点list
    QVector<NodeMap> m_mapList;               //maplist
    QVector<NodeMap> copyList;               //查询list
    QMap<QString,QString> ComponentMapCodeId;
    QMap<QString,QString> CodeIdMapComponent;
    QMap<QString,QVector<NodeMap*>> m_maplength4;
    QMap<QString,QVector<NodeMap*>> m_maplength6;
    QMap<QString,QVector<NodeMap*>> m_maplength8;
    QMap<QString,QVector<NodeMap*>> m_maplength10;
    QVector<QMap<QString,QVector<NodeMap*>>> m_mapTotalVector;//map总容器

    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
