#ifndef DATABASE_H
#define DATABASE_H
#pragma once
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QMutex>
#include <QString>

///****************************************************************************
/// @author  : MichaelFeng
/// @date    : 2023/07/04
/// @file    : DataBase.h
/// @brief   : 数据库单例对象类
///----------------------------------------------------------------------------
///                           Change History
///----------------------------------------------------------------------------
///
///****************************************************************************
const QString local_db_dir = "./myDb.db";
class DataBaseObj
{
public:
    static DataBaseObj * getInstance();        //获取单实例

    static bool getConnecttion(QSqlDatabase & conn);   //获取数据库连接对象封装

    static bool destoryDb();       //释放清理数据库对象

    static bool checkTableIsExsit(QSqlDatabase & conobj,QSqlQuery & query);      //检测表格是否存在

    static QStringList BuildSql();               //创建sql


private:
    DataBaseObj();                            //隐藏构造函数，防止用户new对象
private:
    static DataBaseObj * m_Self;          //sqlite数据库静态对象
    QSqlDatabase my_ConnObj;                   //数据库连接对象
    static QMutex my_Mutex;
    static bool my_DbStatus;                    //数据对象当前的打开状态

};




#endif // DATABASE_H
