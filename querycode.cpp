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

//��ʼ������
void QueryCode::initParas()
{

}

//��ʼ���ؼ�
void QueryCode::initCtrls()
{
	initTreeWidget();

	//չ�����нڵ�
	ui.treeWidget->expandAll();

	connect(ui.lineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_inputQueryNode()));

	connect(ui.treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(on_item_clicked(QTreeWidgetItem *, int)));
}
//�ͷŲ���
void QueryCode::unInitParas()
{

}

//�ͷſؼ�
void QueryCode::unInitCtrls()
{

}

//��ʼ�������С
void QueryCode::initResize()
{

}

//��ʼ�����ʹ���
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

//��Ӧ�����ѯ
void QueryCode::on_inputQueryNode()
{
	swit = true;
	QString lineEdit = ui.lineEdit->text().trimmed();
	qDebug() << lineEdit;
	if (lineEdit == "")
	{
		showAllNode();
	}

	//������������һ����������
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
		//�Ե�ǰ�ڵ���б������Ҳ��ҶԱ����Ľڵ������ʾ
		searchItem(item, lineEdit);
	}
}

//�Ե�ǰ�ڵ���б������Ҳ��ҶԱ����Ľڵ������ʾ
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

//��ʾ�ӽڵ�
void QueryCode::showSon(QTreeWidgetItem * item)
{
	//�����ӽڵ�
	for (int i = 0; i < item->childCount(); i++)
	{		
		item->child(i)->setSelected(false);
		item->child(i)->setHidden(0);
		showSon(item->child(i));
	}
}

//��ʾ���ڵ�
void QueryCode::showParent(QTreeWidgetItem * item)
{
	if (item != nullptr)
	{
		//��ȡ��ǰ�ڵ�ĸ��ڵ�
		QTreeWidgetItem * pItem = item->parent();
		if (pItem != nullptr)
		{
			pItem->setHidden(0);
			showParent(pItem);
		}
	}
}

//��ʾ���нڵ�
void QueryCode::showAllNode()
{
	for (int i = 0; i < ui.treeWidget->topLevelItemCount(); i++)
	{
		ui.treeWidget->topLevelItem(i)->setHidden(0);
	}
}

//��Ӧ���
void QueryCode::on_item_clicked(QTreeWidgetItem * item, int col)
{
	ui.lineEdit_Code->setText(item->text(col));
}

//�ı��ж�
void QueryCode::changeSwit(QTreeWidgetItem * item)
{
	if (swit)
	{
		item->setSelected(true);
		on_item_clicked(item, 0);
	}
	swit = false;
}
