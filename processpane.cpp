#include "processpane.h"
#include "ui_processpane.h"

ProcessPane::ProcessPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessPane)
{
    ui->setupUi(this);
}

ProcessPane::~ProcessPane()
{
    delete ui;
}
