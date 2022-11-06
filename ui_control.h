//
// Created by HY D on 2022/11/4.
//

#ifndef QT_UNSPLASH_2_0_UI_CONTROL_H
#define QT_UNSPLASH_2_0_UI_CONTROL_H
#include "net_control.h"
#include <QMainWindow>
#include <QtWidgets>



QT_BEGIN_NAMESPACE
class QWidget;
class QMenuBar;
class QScrollBar;
QT_END_NAMESPACE

class MyWidget :public QWidget{//显示照片的小窗口

};

class ui_control : public QMainWindow{//主应用程序窗口
    Q_OBJECT
public:
    ui_control(QWidget *parent= nullptr);
    ~ui_control()noexcept;


protected:
    void closeEvent(QCloseEvent* e);

private:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    net_control *netControl;



    signals:
        void ui_init_done();//这个信号想去通知net_control对象启动
};




#endif //QT_UNSPLASH_2_0_UI_CONTROL_H
