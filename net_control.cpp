//
// Created by HY D on 2022/11/4.
//

#include "net_control.h"


net_control::net_control() {

}
net_control::~net_control() {

}

void net_control::run() {
//    r = cpr::Get(cpr::Url{"https://api.github.com/repos/libcpr/cpr/contributors"},
//                 cpr::Parameters{{"client_id", "uKJesDOGYUfEnRbuPA0r-kDyL0dvNkDwZX6enJ6qI8I"}});
//    std::cout << r.text;
//    QByteArray jsonByteArray = QByteArray::fromStdString(r.text);
    QTime curTimer = QTime::currentTime().addMSecs(2000);
    while (QTime::currentTime()< curTimer){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
    QFile picture_info_json = QFile("save1.json");//这是相对路径，也就是程序所在文件夹/save1.json
    if(!picture_info_json.open(QIODevice::ReadOnly)){
        qWarning("Couldn't open save file.");
    }else {
        QByteArray jsonByteArray = picture_info_json.readAll();
        picture_info_json.close();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonByteArray);
        QJsonArray jsonArray = jsonDocument.array();
        std::vector<QJsonObject> jsonObjects = {};
        for (QJsonArray::iterator i = jsonArray.begin(); i != jsonArray.end(); i++) {
            jsonObjects.push_back(i->toObject());
        }
        std::cout << jsonObjects[1]["width"].toInt();
    }
}

void net_control::signal_launch() {
    this->start();
}