﻿#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    DanmakuWidget w;
    w.show();

    return app.exec();
}
