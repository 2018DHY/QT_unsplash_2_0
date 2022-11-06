//
// Created by HY D on 2022/11/4.
//

#ifndef QT_UNSPLASH_2_0_WALLPAPER_SET_CONTROL_H
#define QT_UNSPLASH_2_0_WALLPAPER_SET_CONTROL_H
#include <QObject>
#include <QString>
#include <QThread>

class wallpaper_set_control :public QThread{

Q_OBJECT

public:


    static wallpaper_set_control* Get_Instance();

private:
    wallpaper_set_control();
    wallpaper_set_control(const wallpaper_set_control &);
    ~wallpaper_set_control();
    wallpaper_set_control& operator = (const wallpaper_set_control &)=delete;



    QString Folder;//图片所在文件夹绝对位置
    QString Num;//图片编号转化为文字
    QString File;//图片文件具体位置
    QString osascript;//用于设置桌面背景的命令
    static wallpaper_set_control* m_instance;//唯一实例
};




#endif //QT_UNSPLASH_2_0_WALLPAPER_SET_CONTROL_H
