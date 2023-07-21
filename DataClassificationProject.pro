QT       += core gui sql winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# QXlsx code for Application Qt project
QXLSX_PARENTPATH=./excel/         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=./excel/header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=./excel/source/  # current QXlsx source path is ./source/
include(./excel/QXlsx.pri)


SOURCES += \
    excelprocessing.cpp \
    main.cpp \
    DataBase/DataBase.cpp \
    mainwindow.cpp \
    processpane.cpp \
    querycode.cpp

HEADERS += \
    Public/PublicApi/publicDbFunc.h \
    Public/publicstruct.h \
    excelprocessing.h \
    DataBase/DataBase.h \
    mainwindow.h \
    processpane.h \
    querycode.h

FORMS += \
    mainwindow.ui \
    processpane.ui \
    querycode.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
