#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "QSize"
#include "QPushButton"
#include "QApplication"
#include "QObject"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    //设定主页面大小
    QSize size_ui(1300,1000);
    this->resize(size_ui);

    ui->title->setText("检测缺陷系统");

    //进入单张检测子页面
    connect(ui->pushButton_detect_one, &QPushButton::click,
            this,&MainWidget::on_pushButton_detect_one_released);

    //返回主页面
    connect(&detect_one, &Detect_one_from::back_signal,
            this, &MainWidget::deal_back);
}

MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::on_pushButton_detect_one_released()
{
    this->hide();
    detect_one.show();

}

void MainWidget::deal_back()
{
    detect_one.hide();
    this->show();

}


void MainWidget::on_pushButton_close_clicked()
{
    this->close();
}
