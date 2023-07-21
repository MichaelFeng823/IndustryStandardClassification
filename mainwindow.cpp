#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DataBase/DataBase.h"
#include "Public/PublicApi/publicDbFunc.h"
#include <QFileDialog>
#include <QApplication>
#include <QClipboard>
#include <QMetaType>
#include "processpane.h"
using namespace DataQuery;
using namespace DataInsert;
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initConnect();
    initDB();
    initExcelThread();
    initRootData();
    initSonData();
    bindSonToRoot();
    initTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//初始化excel子线程
void MainWindow::initExcelThread()
{
    thread = new QThread;
    excelThread = new ExcelProcessing;
    excelThread->moveToThread(thread);
    connect(thread,&QThread::started,excelThread,&ExcelProcessing::importexcel);
    connect(excelThread,SIGNAL(FinishedRoot(QVariant)),this,SLOT(onExcelImportRootFinished(QVariant)));
    connect(excelThread,SIGNAL(FinishedSon(QVariant)),this,SLOT(onExcelImportSonFinished(QVariant)));
}
//初始化数据库
void MainWindow::initDB()
{
    hasConnected = DataBaseObj::getConnecttion(coon);
}
//初始化连接
void MainWindow::initConnect()
{
    connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(on_inputQueryNode()));
    connect(ui->ImportRootButton,&QPushButton::clicked,this,&MainWindow::onImportRootButtonClicked);
    connect(ui->ImportSonButton,&QPushButton::clicked,this,&MainWindow::onImportSonButtonClicked);
    connect(ui->treeWidget,&QTreeWidget::itemDoubleClicked,this,&MainWindow::onItemDoubleClicked);
}
void MainWindow::onImportRootButtonClicked()
{
    QString Dir = "./";
    QString filepath = QFileDialog::getOpenFileName(NULL,"选择Excel",Dir,"*.xlsx *.xls");
    excelThread->setExcelPath(filepath);
    excelThread->setExcelType(ExcelType::GJB_Root_Level);
    openProcessPane();
    startExcelThread();
}
void MainWindow::onImportSonButtonClicked()
{
    QString Dir = "./";
    QString filepath = QFileDialog::getOpenFileName(NULL,"选择Excel",Dir,"*.xlsx *.xls");
    excelThread->setExcelPath(filepath);
    excelThread->setExcelType(ExcelType::GJB_Son_Level);
    openProcessPane();
    startExcelThread();
}
void MainWindow::onItemDoubleClicked(QTreeWidgetItem *item,int column)
{
    QString text = item->text(column);
    QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针
    clipboard->clear(); //清空剪切板
    QString codeid = item->statusTip(0);
    clipboard->setText(codeid);
    ui->lineEdit->setText(text);
}
//响应输入查询
void MainWindow::on_inputQueryNode()
{
    ui->treeWidget->expandAll();
    swit = true;
    QString lineEdit = ui->lineEdit->text().trimmed();
    qDebug() << lineEdit;
    if(lineEdit == "")
        showAllNode();
    lineEdit = checkInputIsCodeId(lineEdit);
    //对整个树进行一级遍历索引
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem * item = ui->treeWidget->topLevelItem(i);
        item->setSelected(false);
        if (isAllContains(item->text(0),lineEdit))
        {
            changeSwit(item);
            item->setHidden(0);
        }
        else
        {
            item->setHidden(1);
        }
        //对当前节点进行遍历查找并且对遍历的节点进行显示
        searchItem(item, lineEdit);
    }
}
//检测输入内容是否为CodeId
QString MainWindow::checkInputIsCodeId(QString text)
{
    QString str = text;
    const char *s = text.toStdString().c_str();
    while(*s && *s>='0' && *s<='9')s++;
    if(!bool(*s)){
        str = CodeIdMapComponent[text];
    }
    return str;
}
//是否全包含
bool MainWindow::isAllContains(QString text,QString subtext)
{
    bool isallcontain = true;
    for(int j = 0 ; j < subtext.length(); j++){
        if(!text.contains(subtext[j])){
           isallcontain = false;
        }
    }
    return isallcontain;
}
//清除MAP内容的残留指针对象
void MainWindow::clearMapLength(QMap<QString,QVector<NodeMap*>> m_maplength)
{
    for(QString key:m_maplength.keys()){
        for(NodeMap * node:m_maplength[key]){
            delete node;
        }
    }
    m_maplength.clear();
}
//当excel导入完成
void MainWindow::onExcelImportRootFinished(QVariant var)
{
    QVector<RootLevel> rootlist = var.value<QVector<RootLevel>>();
    closeProcessPane();
    updateData();
    thread->quit();
}
//当excel导入完成
void MainWindow::onExcelImportSonFinished(QVariant var)
{
    QVector<SonLevel> sonlist = var.value<QVector<SonLevel>>();
    closeProcessPane();
    updateData();
    thread->quit();
}

//保存根节点数据
bool MainWindow::saveRootData(QVector<RootLevel> rootlist)
{
    QSqlQuery query;
    RootInsert(coon,query,rootlist);
}
//保存子节点数据
bool MainWindow::saveSonData(QVector<SonLevel> sonlist)
{
    QSqlQuery query;
    SonInsert(coon,query,sonlist);
}
//对当前节点进行遍历查找并且对遍历的节点进行显示
void MainWindow::searchItem(QTreeWidgetItem * item, QString keywords)
{
    if (item != nullptr)
    {
        for (int i = 0; i < item->childCount(); i++)
        {
            QTreeWidgetItem * cItem = item->child(i);
            cItem->setSelected(false);
            qDebug() << cItem->text(0);
            if (cItem != nullptr)
            {

                if (isAllContains(cItem->text(0),keywords))
                {
                    changeSwit(cItem);
                    cItem->setHidden(0);
                    cItem->setExpanded(1);
                    showSon(cItem);
                    showParent(cItem);
                }
                else
                {
                    cItem->setHidden(1);
                    searchItem(cItem, keywords);
                }
            }
        }
    }
}
//开启Excel线程
void MainWindow::startExcelThread()
{
    //if(thread->isRunning())
    //    thread->wait();
    thread->start();
}
//开启processpane窗口
void MainWindow::openProcessPane()
{
    if(processpane == nullptr){
        processpane = new ProcessPane(this);
        processpane->show();
    }
}
//关闭processpane窗口
void MainWindow::closeProcessPane()
{
    if(processpane != nullptr)
        processpane->close();
    delete processpane;
    processpane = nullptr;
}
//刷新数据
void MainWindow::updateData()
{
    initRootData();
    initSonData();
    bindSonToRoot();
    initTree();
}
//显示子节点
void MainWindow::showSon(QTreeWidgetItem * item)
{
    //遍历子节点
    for (int i = 0; i < item->childCount(); i++)
    {
        item->child(i)->setSelected(false);
        item->child(i)->setHidden(0);
        showSon(item->child(i));
    }
}

//显示父节点
void MainWindow::showParent(QTreeWidgetItem * item)
{
    if (item != nullptr)
    {
        //获取当前节点的父节点
        QTreeWidgetItem * pItem = item->parent();
        if (pItem != nullptr)
        {
            pItem->setHidden(0);
            showParent(pItem);
        }
    }
}
//改变判断
void MainWindow::changeSwit(QTreeWidgetItem * item)
{
    if (swit)
    {
        item->setSelected(true);
        //on_item_clicked(item, 0);
    }
    swit = false;
}
//显示所有节点
void MainWindow::showAllNode()
{
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
    {
        ui->treeWidget->topLevelItem(i)->setHidden(0);
    }
}

//初始化根节点数据
void MainWindow::initRootData()
{
    QSqlQuery query;
    RootListQurey(query,m_rootList);
}
//初始化子节点数据
void MainWindow::initSonData()
{
    QSqlQuery query;
    SonListQurey(query,m_sonList);
}
//绑定子节点到父节点上
void MainWindow::bindSonToRoot()
{
    ComponentMapCodeId.clear();
    CodeIdMapComponent.clear();
    for(RootLevel root: m_rootList){
        ComponentMapCodeId[root.componentName] = root.codeId;
        CodeIdMapComponent[root.codeId] = root.componentName;
    }
    for(SonLevel son : m_sonList){
        ComponentMapCodeId[son.componentName] = son.codeId;
        CodeIdMapComponent[son.codeId] = son.componentName;
    }
    bindSonToSon();
}
//绑定次子节点到子节点上
void MainWindow::bindSonToSon()
{
    clearMapLength(m_maplength4);
    clearMapLength(m_maplength6);
    clearMapLength(m_maplength8);
    clearMapLength(m_maplength10);
    for(int i =1; i <=4; i++){
        for(int j = 0; j < m_sonList.size(); j++){
            NodeMap * node = new NodeMap;
            node->CodeId = m_sonList[j].codeId;
            node->ComponentName = m_sonList[j].componentName;
            if(m_sonList[j].codeId.length() == 6 && i == 1){
                m_maplength4[m_sonList[j].parentCodeId].append(node);
            }
            else if(m_sonList[j].codeId.length() == 8 && i == 2){
                m_maplength6[m_sonList[j].parentCodeId].append(node);
            }
            else if(m_sonList[j].codeId.length() == 10 && i == 3){
                m_maplength8[m_sonList[j].parentCodeId].append(node);
            }
            else if(m_sonList[j].codeId.length() == 12 && i == 4){
                m_maplength10[m_sonList[j].parentCodeId].append(node);
            }
        }
    }
    m_mapTotalVector.clear();
    m_mapTotalVector.append(m_maplength4);
    m_mapTotalVector.append(m_maplength6);
    m_mapTotalVector.append(m_maplength8);
    m_mapTotalVector.append(m_maplength10);
}
//初始化树
void MainWindow::initTree()
{
    ui->treeWidget->clear();
    for(RootLevel root:m_rootList)
    {
        QTreeWidgetItem * item = new QTreeWidgetItem(ui->treeWidget,QStringList(root.componentName));
        item->setStatusTip(0,root.codeId);
        initFirstLevelRode(item,root.codeId);
        //initRode(item,iterations,root.codeId,m_mapTotalVector);
    }
    ui->treeWidget->expandAll();
}
////初始化节点
//void MainWindow::initRode(QTreeWidgetItem * item,int & iterations,QString key,QVector<QMap<QString,QVector<NodeMap*>>> mapvector)
//{
////    if(iterations >= 4 || mapvector[iterations-1][key].size() == 0)
////    {
////        --iterations;
////        return;
////    }

////    QVector<NodeMap*> vector = mapvector[iterations-1][key];
////    for(int i = 0; i < vector.size();i++){
////        QTreeWidgetItem * sonitem = new QTreeWidgetItem(item,QStringList(vector[i]->ComponentName));
////        initFirstLevelRode(sonitem,++iterations,vector[i]->CodeId,mapvector);
////    }

//}
 //初始化1级节点
void MainWindow::initFirstLevelRode(QTreeWidgetItem * item, QString key)
{
    QVector<NodeMap*> vector = m_mapTotalVector[0][key];
    for(int i = 0; i < vector.size();i++){
        QTreeWidgetItem * sonitem = new QTreeWidgetItem(item,QStringList(vector[i]->ComponentName));
        sonitem->setStatusTip(0,vector[i]->CodeId);
        initSecondLevelRode(sonitem,vector[i]->CodeId);
    }

}
 //初始化2级节点
void MainWindow::initSecondLevelRode(QTreeWidgetItem * item, QString key)
{
    QVector<NodeMap*> vector = m_mapTotalVector[1][key];
    for(int i = 0; i < vector.size();i++){
        QTreeWidgetItem * sonitem = new QTreeWidgetItem(item,QStringList(vector[i]->ComponentName));
        sonitem->setStatusTip(0,vector[i]->CodeId);
        initThridLevelRode(sonitem,vector[i]->CodeId);
    }

}
//初始化3级节点
void MainWindow::initThridLevelRode(QTreeWidgetItem * item, QString key)
{
    QVector<NodeMap*> vector = m_mapTotalVector[2][key];
    for(int i = 0; i < vector.size();i++){
        QTreeWidgetItem * sonitem = new QTreeWidgetItem(item,QStringList(vector[i]->ComponentName));
        sonitem->setStatusTip(0,vector[i]->CodeId);
        initFourthLevelRode(sonitem,vector[i]->CodeId);
    }

}
//初始化4级节点
void MainWindow::initFourthLevelRode(QTreeWidgetItem * item, QString key)
{
    QVector<NodeMap*> vector = m_mapTotalVector[3][key];
    for(int i = 0; i < vector.size();i++){
        QTreeWidgetItem * sonitem = new QTreeWidgetItem(item,QStringList(vector[i]->ComponentName));
        sonitem->setStatusTip(0,vector[i]->CodeId);
    }
}




