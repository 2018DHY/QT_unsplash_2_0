//
// Created by HY D on 2022/11/4.
//

#include "wallpaper_set_control.h"

wallpaper_set_control* wallpaper_set_control::m_instance = new wallpaper_set_control();

wallpaper_set_control::wallpaper_set_control() {
    Num = "";
    File = "";
    Folder = "";
    osascript = ("osascript -e \'tell application \"Finder\" to set desktop picture to POSIX file");
}
wallpaper_set_control::wallpaper_set_control(const wallpaper_set_control &){
    //do nothing
}
wallpaper_set_control::~wallpaper_set_control(){
    //do nothing
}


wallpaper_set_control* wallpaper_set_control::Get_Instance() {
    return m_instance;
}
