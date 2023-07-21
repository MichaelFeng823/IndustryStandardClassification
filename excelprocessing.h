#ifndef EXCELPROCESSING_H
#define EXCELPROCESSING_H

#include <QObject>
#include <Public/PublicStruct.h>
#include <QVariant>
#include <QSqlDatabase>
#include <QSqlQuery>
///****************************************************************************
/// @author  : MichaelFeng
/// @date    : 2023/07/04
/// @file    : excelprocessing.h
/// @brief   : excel处理模块-----继承自Qobject 默认为多线程执行
///----------------------------------------------------------------------------
///                           Change History
///----------------------------------------------------------------------------
///
///****************************************************************************
enum ExcelType
{
    GJB_Root_Level = 1,
    GJB_Son_Level
};
class ExcelProcessing : public QObject
{
    Q_OBJECT
public:
    explicit ExcelProcessing(QObject *parent = nullptr);
    void setExcelPath(QString excelpath){m_CurrentExcelPath = excelpath;}
    void setExcelType(ExcelType exceltype){m_ExcelType = exceltype;}

    bool importFirstLevelExcel(QString excelpath);                //导入一级目录excel
    bool importSecondLevelExcel(QString excelpath);               //导入二级目录excel
protected:
    QSqlDatabase openDataBase();
    void closeDataBase();
signals:
    void FinishedRoot(QVariant);
    void FinishedSon(QVariant);
public slots:
    void importexcel();                                           //导入excel
private:
    QVector<RootLevel> rootList;                                  //一级目录节点集合
    QVector<SonLevel>  sonList;                                    //子级目录节点集合
    QString m_CurrentExcelPath;                                   //当前excel路径
    ExcelType m_ExcelType;                                        //当前导入文件的类型
};


#endif // EXCELPROCESSING_H
