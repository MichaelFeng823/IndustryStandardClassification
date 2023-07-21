#include "DataBase.h"
#include <QMutexLocker>
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QVariantList>

DataBaseObj * DataBaseObj::m_Self = NULL;
QMutex DataBaseObj::my_Mutex;
bool DataBaseObj::my_DbStatus = false;
DataBaseObj::DataBaseObj()
{

}
//获取单实例
 DataBaseObj * DataBaseObj::getInstance()
 {
     if(DataBaseObj::m_Self == NULL){
         //防止多线程创造两个对象
         QMutexLocker locker(&DataBaseObj::my_Mutex);
         //再判断一次，防止其他线程抢先new过对象
         if(DataBaseObj::m_Self == NULL){
             DataBaseObj::m_Self = new DataBaseObj();
         }
     }

    //返回单实例
     return DataBaseObj::m_Self;
 }
///获取数据库连接对象封装()
bool DataBaseObj::getConnecttion(QSqlDatabase & conn)
{
    //是否成功
   bool isSucc = true;
   QString app_dir;
#ifdef Q_OS_WIN
   app_dir = QApplication::applicationDirPath();
#endif
   //获取单实例
    DataBaseObj * singleTon = DataBaseObj::getInstance();

   //加锁
   QMutexLocker lockers(&DataBaseObj::my_Mutex);
   if(!singleTon->my_DbStatus){

       QStringList driverlist = QSqlDatabase::drivers();
       for(int i = 0; i <driverlist.size(); i++)
       {
           qDebug() << driverlist[i];
       }
       singleTon->my_ConnObj = QSqlDatabase::addDatabase("QSQLITE");
       //设置数据库名，添加内存数据库。
       singleTon->my_ConnObj.setDatabaseName(local_db_dir);
      //若未打开数据库则显示错误，
       if(!singleTon->my_ConnObj.open())
       {
           QMessageBox::warning(0,"error",singleTon->my_ConnObj.lastError().text());
          qDebug() << singleTon->my_ConnObj.lastError();
           return false;
       }
       else
       {
           qDebug() << "DataBase is open!";
           singleTon->my_DbStatus = true;
       }
       QSqlQuery sqlquery(singleTon->my_ConnObj);
       singleTon->my_ConnObj.transaction();
       if(checkTableIsExsit(singleTon->my_ConnObj,sqlquery))
           singleTon->my_ConnObj.commit();
       if(isSucc)
           conn = m_Self->my_ConnObj;
       return true;
   }
   else
   {
       qDebug() << "database already open";
       conn = singleTon->my_ConnObj;
       return true;
   }
}
//创建sql
QStringList DataBaseObj::BuildSql()
{
    qDebug() << "初始化sql语句";
    QStringList sqlist;
    sqlist  <<    "create table if not exists GJBRootDirectory(CodeID INTEGER ,ComponentName varchar(64) default '');";
    sqlist  <<    "create table if not exists GJBSonDirectory(CodeID INTEGER ,ParentCodeID INTEGER ,ComponentName varchar(64) default '');";


    return sqlist;
}

 bool DataBaseObj::checkTableIsExsit(QSqlDatabase & conobj,QSqlQuery & query)     //检测表格是否存在 不存在则建表
 {
      QStringList sqllist = BuildSql();
      bool query_ret = false;

         for(QString str:sqllist){
             qDebug() << "sql:"+str;
             query.prepare(str);
             query_ret = query.exec();
             query.clear();
             if(!query_ret){
                 qDebug() << "error:"+conobj.lastError().text();
                 m_Self->my_ConnObj.rollback();
                 break;
             }
             qDebug() << "query_result:" <<  query_ret;
         }
     return true;
 }
//释放清理数据库对象
bool DataBaseObj::destoryDb()
{


}

