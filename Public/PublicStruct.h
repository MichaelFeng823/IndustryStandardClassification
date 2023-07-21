#ifndef PUBLICSTRUCT_H
#define PUBLICSTRUCT_H
#include <QString>
#include <QMetaType>

///****************************************************************************
/// @author  : MichaelFeng
/// @date    : 2023/07/04
/// @file    : publicstruct.h
/// @brief   : 公共数据结构对象
///----------------------------------------------------------------------------
///                           Change History
///----------------------------------------------------------------------------
///
///****************************************************************************

struct RootLevel
{
    QString codeId;
    QString componentName;
};

struct SonLevel
{
    QString codeId;
    QString parentCodeId;
    QString componentName;
};
Q_DECLARE_METATYPE(RootLevel);
Q_DECLARE_METATYPE(SonLevel);

#endif // PUBLICSTRUCT_H

