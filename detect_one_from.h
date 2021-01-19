#ifndef DETECT_ONE_FROM_H
#define DETECT_ONE_FROM_H

#include <QWidget>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
#include <QImage>
#include <QtDebug>
#include <QTimer>     // 设置采集数据的间隔时间
#include "cv.h"
#include "highgui.h"
#include <opencv2/imgproc/types_c.h>
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include <opencv2/imgproc/types_c.h>

using namespace cv;

namespace Ui {
class Detect_one_from;
}

class Detect_one_from : public QWidget
{
    Q_OBJECT

public:
    explicit Detect_one_from(QWidget *parent = nullptr);
    ~Detect_one_from();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_begin_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_detect_clicked();

    void readFarme();

private:
    Ui::Detect_one_from *ui;
    QTimer    *timer;
//    QImage    *imag;
//    CvCapture *cam;// 视频获取结构， 用来作为视频获取函数的一个参数
//    IplImage  *frame;//申请IplImage类型指针，就是申请内存空间来存放每一帧图像

    Mat m_cv_img;
    QImage m_qt_img;
    VideoCapture m_cap;


signals:
    void back_signal();
};

#endif // DETECT_ONE_FROM_H
