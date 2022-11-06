cmake_minimum_required(VERSION 3.23)
project(QT_unsplash_2_0)

set(CMAKE_CXX_STANDARD 17)
set(Qt5_DIR /Users/dhy/Qt/5.15.2/clang_64/lib/cmake/Qt5/)#需要设置自己电脑qt所在位置
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)


add_executable(QT_unsplash_2_0 main.cpp net_control.cpp net_control.h /
        ui_control.cpp ui_control.h wallpaper_set_control.cpp wallpaper_set_control.h /
        picture_info.cpp picture_info.h)


target_link_libraries(QT_unsplash_2_0
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        cpr::cpr
        )