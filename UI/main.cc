#include <QApplication>
#include <memory>
#include "connector.h"
#include "gpswindow.h"



int main(int argc, char **argv) {
    //set up everything
    Connector c;
    QApplication app(argc, argv);

    GPSWindow w(500, std::shared_ptr<Connector>(&c));
    //run all threads



    //end the program
    w.show();
    app.exec();
    return 0;
}
