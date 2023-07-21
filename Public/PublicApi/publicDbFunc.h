#ifndef PUBLICDBFUNC_H
#define PUBLICDBFUNC_H
#pragma once
#include <QSqlQuery>
#include <QVariant>
#include <QSettings>
#include <QVector>
#include <QDebug>
#include <QSqlError>
#include "../PublicStruct.h"

namespace DataQuery {
    //根节点数据查询
    inline int RootListQurey(QSqlQuery & query, QVector<RootLevel> & rootList)
    {
        rootList.clear();
        int queryCounts = -1;
        QString sql = QString("select * from GJBRootDirectory");
        query.prepare(sql);
        if(!query.exec()){
            qDebug() << "File:" << __FILE__<<"Line:" << __LINE__ << endl;
            qDebug() << "billQurey Error:query.exec() = False";
            qDebug() << "the sql is:" << sql.toStdString().c_str() << endl;
        }
        else{
            queryCounts = 0;
            while(query.next()){
                queryCounts++;
                RootLevel root;
                root.codeId = query.value("CodeID").toString();
                root.componentName = query.value("ComponentName").toString();
                rootList.append(root);
            }
        }
        return queryCounts;
    }
    //子节点数据查询
    inline int SonListQurey(QSqlQuery & query, QVector<SonLevel> & sonList)
    {
        sonList.clear();
        int queryCounts = -1;
        QString sql = QString("select * from GJBSonDirectory");
        query.prepare(sql);
        if(!query.exec()){
            qDebug() << "File:" << __FILE__<<"Line:" << __LINE__ << endl;
            qDebug() << "billQurey Error:query.exec() = False";
            qDebug() << "the sql is:" << sql.toStdString().c_str() << endl;
        }
        else{
            queryCounts = 0;
            while(query.next()){
                queryCounts++;
                SonLevel son;
                son.codeId = query.value("CodeID").toString();
                son.parentCodeId = query.value("ParentCodeID").toString();
                son.componentName = query.value("ComponentName").toString();
                sonList.append(son);
            }
        }
        return queryCounts;
    }
}

namespace DataInsert {
     //根节点新增数据插入
    inline int RootInsert(QSqlDatabase & database,QSqlQuery & query,QVector<RootLevel> & rootlist)
    {
        int queryResult = 1;
        QString sql = QString("insert into GJBRootDirectory(CodeID,ComponentName) values(?,?);");
        query.prepare(sql);
        QVariantList CodeIDList;
        QVariantList ComponentNameList;
        for(RootLevel root : rootlist){
            CodeIDList << root.codeId;
            ComponentNameList << root.componentName;
        }
        query.addBindValue(CodeIDList);
        query.addBindValue(ComponentNameList);
        if(!query.execBatch()){
            qDebug() << "RootInsert Error:query.exec() = False" << endl;
            qDebug() << database.lastError();
            database.rollback();
            queryResult = -1;
        }
        else{
            if(rootlist.size() > 0 && queryResult ==1)
                 database.commit();
        }
        return queryResult;
    }
    //根节点新增数据插入
   inline int SonInsert(QSqlDatabase & database,QSqlQuery & query,QVector<SonLevel> & sonlist)
   {
       int queryResult = 1;
       QString sql = QString("insert into GJBSonDirectory(CodeID,ParentCodeID,ComponentName) values(?,?,?);");
       query.prepare(sql);
       QVariantList CodeIDList;
       QVariantList ParentIdList;
       QVariantList ComponentNameList;
       for(SonLevel son : sonlist){
           CodeIDList << son.codeId;
           ParentIdList << son.parentCodeId;
           ComponentNameList << son.componentName;
       }
       query.addBindValue(CodeIDList);
       query.addBindValue(ParentIdList);
       query.addBindValue(ComponentNameList);
       if(!query.execBatch()){
           qDebug() << "SonInsert Error:query.exec() = False" << endl;
           database.rollback();
           queryResult = -1;
       }
       else{
           if(sonlist.size() > 0 && queryResult ==1)
                database.commit();
       }

       return queryResult;
   }
}

namespace DataUpdate {
     //账单数据修改
//    inline int billUpdate(QSqlDatabase & database,QSqlQuery & query,BillTableStruct & billStrcut)
//    {
//        int queryResult = -1;
//        QString sql = QString("update BillTable set Year = '%1',Month = '%2',Day = '%3',MoneyAmount = '%4',Remark = '%5',UserId = '%6',TypeId = '%7',InOrOut = '%8' where BillNo = '%9';").arg(billStrcut.date.year())
//                .arg(billStrcut.date.month()).arg(billStrcut.date.day()).arg(billStrcut.moneyAmount).arg(billStrcut.remarks).arg(billStrcut.userId).arg(billStrcut.typeId).arg(billStrcut.InOrOut).arg(billStrcut.billNo);
//        query.prepare(sql);
//        if(!query.exec()){
//            LOG("File:%sLine:%d",__FILE__,__LINE__);
//            LOG(" billUpdate Error:query.exec() = False");
//            LOG("the sql is:%s",sql.toStdString().c_str());
//            database.rollback();
//        }
//        else{
//            queryResult = 1;
//            database.commit();
//        }
//        LOG("the sql is:%s",sql.toStdString().c_str());
//        LOG("the queryResult is:%d",queryResult);
//        return queryResult;
//    }
}

namespace DataDelete {
     //账单数据删除
//    inline int billDelete(QSqlDatabase & database,QSqlQuery & query,BillTableStruct & billStrcut)
//    {
//        int queryResult = -1;
//        QString sql = QString("delete from  BillTable where BillNo = '%1';").arg(billStrcut.billNo);
//        query.prepare(sql);
//        if(!query.exec()){
//            LOG("File:%sLine:%d",__FILE__,__LINE__);
//            LOG(" billDelete Error:query.exec() = False");
//            LOG("the sql is:%s",sql.toStdString().c_str());
//            database.rollback();
//        }
//        else{
//            queryResult = 1;
//            database.commit();
//        }
//        LOG("the sql is:%s",sql.toStdString().c_str());
//        LOG("the queryResult is:%d",queryResult);
//        return queryResult;
//    }
}

#endif // PUBLICDBFUNC_H
