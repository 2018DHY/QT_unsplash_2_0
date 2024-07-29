//
// Created by HY D on 2022/11/4.
//

#ifndef QT_UNSPLASH_2_0_NET_CONTROL_H
#define QT_UNSPLASH_2_0_NET_CONTROL_H
#include <iostream>
#include <vector>
#include <QtCore>
#include <QObject>
#include <QThread>
#include <cpr/cpr.h>

class QString;
class QJsonArray;



class net_control : public QThread
{
    Q_OBJECT
public:
    net_control();
    ~net_control();

    void run() override;

private:
    cpr::Response r;

public slots:
    void signal_launch();

};


#endif //QT_UNSPLASH_2_0_NET_CONTROL_H
