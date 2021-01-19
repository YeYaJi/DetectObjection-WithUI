#include "detect_one_from.h"
#include "ui_detect_one_from.h"
#include<typeinfo>
#include <iostream>

Detect_one_from::Detect_one_from(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Detect_one_from)
{
    ui->setupUi(this);
    // 初始化参数

    timer = new QTimer(this); //使用QTimer来代替waitkey

    // 设定检测一张的页面大小
    QSize size_ui(1300,1000);
    this->resize(size_ui);




    // 返回主页面
    connect (ui->pushButton_back, &QPushButton::clicked, this, &Detect_one_from::on_pushButton_back_clicked);
    // 时间到，读取当前摄像头信息
    connect(timer, SIGNAL(timeout()), this, SLOT(readFarme())); //这里非要写QT4标准在能过。。有问题。
//    connect(timer, SIGNAL(timeout()), this, &Detect_one_from::readFarme());

}



Detect_one_from::~Detect_one_from()
{
    delete ui;
}
void Detect_one_from::on_pushButton_back_clicked()
{
    emit back_signal();
}

void Detect_one_from::on_pushButton_begin_clicked()
{
    m_cap.open(0);// 打开摄像头，从摄像头中获取视频
    timer->start(1);// 开始计时，超时则发出timeout()信号1毫秒
}

void Detect_one_from::on_pushButton_stop_clicked()
{
    timer->stop();  // 停止读取数据。
    m_cap.release();// 释放内存；
}

void Detect_one_from::on_pushButton_detect_clicked()
{
//    if (frame==nullptr){
//        std::cout<<"没有读入图片"<<std::endl;
//    }
//    frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧
//    QImage image((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_BGR888);
    ui->label_result_img->setPixmap(QPixmap::fromImage(m_qt_img));  // 将图片显示到label上
}

void Detect_one_from::readFarme(){
//    frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧
//    Mat cv_img_video (Size(frame->width, frame->height), CV_8UC3);
//    // 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
//    QImage image((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_BGR888);
//    ui->label_video_origin->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上


    m_cap>>m_cv_img;
    m_qt_img= QImage((const uchar*)m_cv_img.data, m_cv_img.cols, m_cv_img.rows, QImage::Format_BGR888);
    m_qt_img.bits();//强制深层复制一份QImage,防止Mat释放掉
    ui->label_video_origin->setPixmap(QPixmap::fromImage(m_qt_img));







}
