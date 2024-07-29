//
// Created by HY D on 2022/11/4.
//

#include "ui_control.h"

ui_control::ui_control(QWidget *parent)
{
    if(this->objectName().isEmpty())
        this->setObjectName("QT_unsplash_2");
    QScreen* qScreen = qApp->primaryScreen();

    //设置窗口位置以及大小
    int myApp_size_width = (int)(0.8 * qScreen->size().width());//宽度为屏幕的80%
//    this->resize(myApp_size_width,qScreen->size().height());//高度为屏幕的100%
    this->setGeometry((int)(0.1 * qScreen->size().width()), 0.1 * qScreen->size().height(), myApp_size_width, qScreen->size().height() * 0.8);


    centralwidget = new QWidget(this);//中心窗口初始化
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    this->setCentralWidget(centralwidget);

    menubar = new QMenuBar(this);//菜单栏初始化
    menubar->setObjectName(QString::fromUtf8("menubar"));
    this->setMenuBar(menubar);


    statusbar = new QStatusBar(this);//状态栏初始化
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
//    qDebug()<<statusbar->height();
    this->setStatusBar(statusbar);

    netControl = new net_control();

    connect(this, SIGNAL(ui_init_done()), netControl, SLOT(signal_launch()));
    emit ui_init_done();


}

ui_control::~ui_control() noexcept
{
    delete centralwidget;
    delete menubar;
    delete statusbar;
}



void ui_control::closeEvent(QCloseEvent *e)
{
    qApp->exit();
}
