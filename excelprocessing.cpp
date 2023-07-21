#include "excelprocessing.h"
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include "Public/PublicApi/publicDbFunc.h"
#include <QDebug>
#include <QThread>
using namespace QXlsx;
using namespace  DataInsert;
ExcelProcessing::ExcelProcessing(QObject *parent) : QObject(parent)
{
    //qRegisterMetaType<QVariant>("QVariant");
    //importexcel(QString::fromLocal8Bit("E:/Qt_5.14.2_Project_Save/DataClassificationProject/excel/Doc/FirstLevel.xlsx"),ExcelType::GJB_Root_Level);
    //importexcel(QString::fromLocal8Bit("E:/Qt_5.14.2_Project_Save/DataClassificationProject/excel/Doc/SecondLevel.xlsx"),ExcelType::GJB_Son_Level);
}
//导入excel
void ExcelProcessing::importexcel()
{
    if(m_ExcelType == ExcelType::GJB_Root_Level){
        if(importFirstLevelExcel(m_CurrentExcelPath)){
            QSqlDatabase db = openDataBase();
            QSqlQuery query(db);
            RootInsert(db,query,rootList);
            closeDataBase();
            qDebug() << "import root data successful!" << endl;
            emit FinishedRoot(QVariant::fromValue(rootList));
            }
    }else if(m_ExcelType == ExcelType::GJB_Son_Level){
        if(importSecondLevelExcel(m_CurrentExcelPath)){
            QSqlDatabase db = openDataBase();
            QSqlQuery query(db);
            SonInsert(db,query,sonList);
            closeDataBase();
            qDebug() << "import son data successful!" << endl;
            emit FinishedSon(QVariant::fromValue(sonList));
        }
    }
}
//导入一级目录excel
bool ExcelProcessing::importFirstLevelExcel(QString excelpath)
{

   rootList.clear();
   bool status = false;
   Document xlsxR(excelpath);
   int rowCounts = 0;
   if (xlsxR.load()) //加载Excel文件
   {
       status = true;
       rowCounts = xlsxR.dimension().rowCount();
       for (int row = 1; row <= rowCounts; row++)
       {
           RootLevel root;
           Cell * code = xlsxR.cellAt(row, 1);
           Cell * component = xlsxR.cellAt(row, 2);
           if(code != nullptr && component != nullptr){
               root.codeId = code->readValue().toString();
               root.componentName = component->readValue().toString();
               rootList.append(root);
           }
           else
           {
               qDebug() <<QString::fromLocal8Bit("the root is null").toStdString().c_str();
           }
       }
       qDebug() << "rootList:" << rootList.size() << endl;
   }
   return status;
}
//导入二级目录excel
bool ExcelProcessing::importSecondLevelExcel(QString excelpath)
{
   sonList.clear();
   bool status = false;
   Document xlsxR(excelpath);
   int rowCounts = 0;
   if (xlsxR.load()) //加载Excel文件
   {
       status = true;
       rowCounts = xlsxR.dimension().rowCount();
       for (int row = 1; row <= rowCounts; row++)
       {
           SonLevel son;
           QVector<Cell*> cellList;
           Cell * code1 = xlsxR.cellAt(row, 1);
           Cell * code2 = xlsxR.cellAt(row, 2);
           Cell * code3 = xlsxR.cellAt(row, 3);
           Cell * code4 = xlsxR.cellAt(row, 4);
           Cell * code5 = xlsxR.cellAt(row, 5);
           Cell * code6 = xlsxR.cellAt(row, 6);
           Cell * component = xlsxR.cellAt(row, 7);
           cellList << code1 << code2 << code3 << code4 << code5 << code6;
           for(Cell * cell :cellList){
               if(cell != nullptr)
                    son.codeId += cell->readValue().toString().trimmed();
           }
           if(son.codeId.length() > 4){
               son.parentCodeId = son.codeId.left(son.codeId.length()-2);
               if(component != nullptr)
                   son.componentName = component->readValue().toString().trimmed();
               sonList.append(son);
           }
       }
       qDebug() << "sonList:" << sonList.size() << endl;
   }
   return status;
}
QSqlDatabase ExcelProcessing::openDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", QString::number((quint64)QThread::currentThreadId()));
    db.setDatabaseName("./myDb.db");
    if (!db.open())
    {
        qDebug() << "open database failed:" << endl;
    }
    return db;
}
void ExcelProcessing::closeDataBase()
{
    QString dbName = QString::number((quint64)QThread::currentThreadId());
       {
           QSqlDatabase dbConnected = QSqlDatabase::database(dbName);
           if (dbConnected.isValid())
           {
               dbConnected.close();
           }
       }
       QSqlDatabase::removeDatabase(dbName);
}


