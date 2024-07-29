//
// Created by HY D on 2022/11/4.
//

#include "net_control.h"
#include <QFileInfo>
#include <QRandomGenerator>
#include <QDebug>





net_control::net_control()
{

}
net_control::~net_control()
{

}

void net_control::run()
{

    // QTime curTimer = QTime::currentTime().addMSecs(2000);
    // while(QTime::currentTime() < curTimer) {
    //     QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    // }
    // QThread::msleep(2000);
    r = cpr::Get(cpr::Url{"https://api.unsplash.com/photos"},
    cpr::Parameters{{"client_id", "uKJesDOGYUfEnRbuPA0r-kDyL0dvNkDwZX6enJ6qI8I"}});
    qDebug() << QString::fromStdString(r.text);
    if(r.status_code != 200) {
        qDebug() << "网站访问失败";
        return ;
    }
    QByteArray jsonByteArray = QByteArray::fromStdString(r.text);


    QString randfile = "net_json_";
    QRandomGenerator rand;
    auto num = rand.generate();
    randfile.append(QString::number(num)).append(".json");

    QFile picture_info_json = QFile(randfile);//这是相对路径，也就是程序所在文件夹
    if(picture_info_json.open(QIODevice::Append)) {
        QTextStream txtstream(&picture_info_json);
        txtstream << QString::fromStdString(r.text);
        picture_info_json.close();
    }



    // QFileInfo info;
    // if(!info.exists("save1.json")){
    //     QFile("save1.json").
    // }
    // if(!picture_info_json.open(QIODevice::ReadOnly)) {
    //     qWarning("Couldn't open save file.");
    // } else {
    //     QByteArray jsonByteArray = picture_info_json.readAll();
    //     picture_info_json.close();
    //     QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonByteArray);
    //     QJsonArray jsonArray = jsonDocument.array();
    //     std::vector<QJsonObject> jsonObjects = {};
    //     for(QJsonArray::iterator i = jsonArray.begin(); i != jsonArray.end(); i++) {
    //         jsonObjects.push_back(i->toObject());
    //     }
    //     qDebug() << jsonObjects[1]["width"].toInt();
    // }

}

void net_control::signal_launch()
{
    this->start();
}
