#include <iostream>
#include <QApplication>
#include "ui_control.h"

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    QApplication app(argc,argv);
    ui_control mainwindow;
    mainwindow.show();
    app.exec();
    return 0;
}
