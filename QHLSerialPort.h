#ifndef QHLSERIALPORT_H
#define QHLSERIALPORT_H

#include <QObject>
#include "QSerialPort"
class QHLSerialPort : public QObject
{
    Q_OBJECT
public:
    explicit QHLSerialPort(QObject *parent = 0);

private:
    QSerialPort * m_com;//串口对象指针
    QString receiveString;


signals:

public slots:
    void onComReceiveSlot();
};

#endif // QHLSERIALPORT_H
