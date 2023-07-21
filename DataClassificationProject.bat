echo off
rem 设置打包目录
set DIST_DIR=E:\AutoBuildProjectTest
rem 设置构建目录
set BUILD_DIR=E:\Qt_5.14.2_Project_Save\DataClassificationProject
rem 设置输出目录
set OUT_DIR=E:\BuildOutPut

rem 将mingw对应的路径添加到环境变量
set PATH=T:\Qt5.14.2_SetUpAddress\5.14.2\mingw73_64\bin;T:\Qt5.14.2_SetUpAddress\Tools\mingw730_64\bin;%PATH%

rem 设置QT的目录
set QTDIR=T:\Qt5.14.2_SetUpAddress\5.14.2\mingw73_64\bin\
set QTTOOLDir=T:\Qt5.14.2_SetUpAddress\Tools\mingw730_64\bin

rem 设置需要编译的pro文件的地址
set TARGETPRO=E:\Qt_5.14.2_Project_Save\DataClassificationProject\DataClassificationProject.pro

rem 创建目录并切换目录
mkdir %DIST_DIR% && pushd %DIST_DIR%
mkdir %BUILD_DIR% %OUT_DIR%
pushd %BUILD_DIR%

rem 配置构建参数
%QTDIR%qmake.exe -spec win32-g++ "CONFIG+=release" %TARGETPRO%
%QTTOOLDir%mingw32-make.exe qmake_all
%QTTOOLDir%mingw32-make.exe

rem 构建完成之后清空对应的中间文件
%QTTOOLDir%mingw32-make.exe -f Makefile.Release clean

rem 拷贝出执行程序之后通过windeployqt找出依赖项目
popd
rem 拷贝执行文件
copy %BUILD_DIR%\release\DataClassificationProject.exe %OUT_DIR%\DataClassificationProject.exe

rem 拷贝依赖项目
%QTDIR%windeployqt %OUT_DIR%\DataClassificationProject.exe