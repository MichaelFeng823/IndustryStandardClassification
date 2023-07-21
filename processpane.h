#ifndef PROCESSPANE_H
#define PROCESSPANE_H

#include <QWidget>

namespace Ui {
class ProcessPane;
}

class ProcessPane : public QWidget
{
    Q_OBJECT

public:
    explicit ProcessPane(QWidget *parent = nullptr);
    ~ProcessPane();

private:
    Ui::ProcessPane *ui;
};

#endif // PROCESSPANE_H
