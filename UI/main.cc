#include <QApplication>
#include "gpswindow.h"


int main(int argc, char **argv) {

    QApplication app(argc, argv);

  GPSWindow w(500);
  w.show();

  return app.exec();
}