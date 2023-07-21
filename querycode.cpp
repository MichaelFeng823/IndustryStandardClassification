#include "querycode.h"

#include "qDebug.h"

QueryCode::QueryCode(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initParas();

	initCtrls();
}

QueryCode::~QueryCode()
{
	unInitParas();

	unInitCtrls();
}

//初始化参数
void QueryCode::initParas()
{

}

//初始化控件
void QueryCode::initCtrls()
{
	initTreeWidget();

	//展开所有节点
	ui.treeWidget->expandAll();

	connect(ui.lineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_inputQueryNode()));

	connect(ui.treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(on_item_clicked(QTreeWidgetItem *, int)));
}
//释放参数
void QueryCode::unInitParas()
{

}

//释放控件
void QueryCode::unInitCtrls()
{

}

//初始化界面大小
void QueryCode::initResize()
{

}

//初始化树型窗口
void QueryCode::initTreeWidget()
{
	/*QList<QList<Data_Structs::Code>> codeDataLists;
	QList<Data_Structs::Code> codeDataList;
	code.queryCode(codeDataList);
	for (int i = 0; i < codeDataList.size(); i++)
	{
		qDebug() << codeDataList[i].NAME;
		qDebug() << codeDataList[i].ARRAY;
		QString array = codeDataList[i].ARRAY;
		QList<QString> arrayList = array.split("@");
		qDebug() << arrayList;
	}*/
}

//响应输入查询
void QueryCode::on_inputQueryNode()
{
	swit = true;
	QString lineEdit = ui.lineEdit->text().trimmed();
	qDebug() << lineEdit;
	if (lineEdit == "")
	{
		showAllNode();
	}

	//对整个树进行一级遍历索引
	for (int i = 0; i < ui.treeWidget->topLevelItemCount(); i++)
	{
		QTreeWidgetItem * item = ui.treeWidget->topLevelItem(i);
		item->setSelected(false);
		if (item->text(0).contains(lineEdit))
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

//对当前节点进行遍历查找并且对遍历的节点进行显示
void QueryCode::searchItem(QTreeWidgetItem * item, QString keywords)
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
				if (cItem->text(0).contains(keywords))
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

//显示子节点
void QueryCode::showSon(QTreeWidgetItem * item)
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
void QueryCode::showParent(QTreeWidgetItem * item)
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

//显示所有节点
void QueryCode::showAllNode()
{
	for (int i = 0; i < ui.treeWidget->topLevelItemCount(); i++)
	{
		ui.treeWidget->topLevelItem(i)->setHidden(0);
	}
}

//响应点击
void QueryCode::on_item_clicked(QTreeWidgetItem * item, int col)
{
	ui.lineEdit_Code->setText(item->text(col));
}

//改变判断
void QueryCode::changeSwit(QTreeWidgetItem * item)
{
	if (swit)
	{
		item->setSelected(true);
		on_item_clicked(item, 0);
	}
	swit = false;
}
