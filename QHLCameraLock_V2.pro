QT += core
QT -= gui
QT += serialport

TARGET = QHLCameraLock_V2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    QHLSerialPort.cpp

DISTFILES += \
    README.md

HEADERS += \
    QHLSerialPort.h \
    QHLCommunicationTypeCmd.h

