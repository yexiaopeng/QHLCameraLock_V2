#include <QCoreApplication>
#include "QHLSerialPort.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHLSerialPort hlport;

    return a.exec();
}

