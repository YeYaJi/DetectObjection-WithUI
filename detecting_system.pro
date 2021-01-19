QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

#引入opnecv库
INCLUDEPATH += /usr/include/opencv
INCLUDEPATH += /usr/include/opencv2
INCLUDEPATH += /usr/include/opencv2/core
INCLUDEPATH += /usr/include/opencv2/highgui
INCLUDEPATH += /usr/include/opencv2/imgproc
INCLUDEPATH += /usr/include/opencv2/flann
INCLUDEPATH += /usr/include/opencv2/photo
INCLUDEPATH += /usr/include/opencv2/video
INCLUDEPATH += /usr/include/opencv2/features2d
INCLUDEPATH += /usr/include/opencv2/objdetect
INCLUDEPATH += /usr/include/opencv2/calib3d
INCLUDEPATH += /usr/include/opencv2/ml
INCLUDEPATH += /usr/include/opencv2/contrib


#LIBS += /usr/lib/x86_64-linux-gnu/libopencv_highgui.so \
#        /usr/lib/x86_64-linux-gnu/libopencv_core.so    \
#        /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so \
#        /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so
LIBS += `pkg-config opencv --cflags --libs`
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    detect_one_from.cpp \
    main.cpp \
    mainwidget.cpp

HEADERS += \
    detect_one_from.h \
    mainwidget.h

FORMS += \
    detect_one_from.ui \
    mainwidget.ui

TRANSLATIONS += \
    detecting_system_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
