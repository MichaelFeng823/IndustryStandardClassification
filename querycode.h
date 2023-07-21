#ifndef QUERYCODE_H
#define QUERYCODE_H

#include <QtWidgets/QWidget>
#include "ui_querycode.h"

//#include "Data/Data_Code.h"

class QueryCode : public QWidget
{
	Q_OBJECT

public:
	QueryCode(QWidget *parent = 0);
	~QueryCode();

private:
	Ui::QueryCodeClass ui;

	//Data_Code code;

	bool swit;

	//初始化参数
	void initParas();

	//初始化控件
	void initCtrls();

	//释放参数
	void unInitParas();

	//释放控件
	void unInitCtrls();

	//初始化界面大小
	void initResize();

	//初始化树型窗口
	void initTreeWidget();

	//对当前节点进行遍历查找并且对遍历的节点进行显示
	void searchItem(QTreeWidgetItem * item, QString keywords);

	//显示子节点
	void showSon(QTreeWidgetItem * item);

	//显示父节点
	void showParent(QTreeWidgetItem * item);

	//显示所有节点
	void showAllNode();

	//改变判断
	void changeSwit(QTreeWidgetItem * item);

private slots:
	//响应输入查询
	void on_inputQueryNode();

	//响应点击
	void on_item_clicked(QTreeWidgetItem * item, int col);
};

#endif // QUERYCODE_H
