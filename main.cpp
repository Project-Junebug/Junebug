#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    MainWindow window;
    window.setFixedSize(400,300);
    window.setWindowTitle("Junebug");
    window.show();

    return app.exec();
}
