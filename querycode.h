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

	//��ʼ������
	void initParas();

	//��ʼ���ؼ�
	void initCtrls();

	//�ͷŲ���
	void unInitParas();

	//�ͷſؼ�
	void unInitCtrls();

	//��ʼ�������С
	void initResize();

	//��ʼ�����ʹ���
	void initTreeWidget();

	//�Ե�ǰ�ڵ���б������Ҳ��ҶԱ����Ľڵ������ʾ
	void searchItem(QTreeWidgetItem * item, QString keywords);

	//��ʾ�ӽڵ�
	void showSon(QTreeWidgetItem * item);

	//��ʾ���ڵ�
	void showParent(QTreeWidgetItem * item);

	//��ʾ���нڵ�
	void showAllNode();

	//�ı��ж�
	void changeSwit(QTreeWidgetItem * item);

private slots:
	//��Ӧ�����ѯ
	void on_inputQueryNode();

	//��Ӧ���
	void on_item_clicked(QTreeWidgetItem * item, int col);
};

#endif // QUERYCODE_H
