#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "detect_one_from.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_pushButton_detect_one_released();
    void deal_back();


    void on_pushButton_close_clicked();

private:
    Ui::MainWidget *ui;
    Detect_one_from detect_one;
};
#endif // MAINWIDGET_H
