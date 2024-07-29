cmake_minimum_required(VERSION 3.23)
project(QT_unsplash_2_0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF)

# include(FetchContent)
# FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
#                          GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
# FetchContent_MakeAvailable(cpr)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)


add_executable(QT_unsplash_2_0 main.cpp net_control.cpp net_control.h /
        ui_control.cpp ui_control.h wallpaper_set_control.cpp wallpaper_set_control.h /
        picture_info.cpp picture_info.h
        file_analyse.qrc
    )


target_link_libraries(QT_unsplash_2_0
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        cpr::cpr
        )
