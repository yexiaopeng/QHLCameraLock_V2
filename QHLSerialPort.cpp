#include "QHLSerialPort.h"

#include "QHLCommunicationTypeCmd.h"
#include "QDebug"


QHLSerialPort::QHLSerialPort(QObject *parent) : QObject(parent){
    //清除接受数据缓存
    receiveString.clear();
    //串口设置
    m_com = new QSerialPort(this);
    m_com->setPortName("/dev/ttySAC0");//对应USART0
    m_com->setBaudRate(115200);
    m_com->setDataBits(QSerialPort::Data8);
    m_com->setFlowControl(QSerialPort::NoFlowControl);
    m_com->setParity(QSerialPort::NoParity);
    m_com->setStopBits(QSerialPort::OneStop);
    //建立接收串口数据的槽函数
    connect(m_com,SIGNAL(readyRead()),this,SLOT(onComReceiveSlot()));

    if(m_com->open(QIODevice::ReadWrite)){
        //发送指令给开锁器，表示设备已启动完成
        m_com->write(QHLCMD_USART_DEVICE_STARTUP_OVERED);
    }else{
        qDebug() << "open serial failed";
    }
}
//接收开锁器的数据并进行处理
//四把锁的模式下
//pleaseopen11lock
//pleaseopen12lock
//pleaseopen21lock
//pleaseopen31lock
//要兼容三把锁的模式
//前门:pleaseopen0lock
//后门:pleaseopen1lock
//右门:pleaseopen2lock
void QHLSerialPort::onComReceiveSlot()
{
    QByteArray data = m_com->readAll();

    receiveString.append(data);

    /*three lock mode*/
    if(receiveString.contains(QHLCMD_USART_OPEN_0_LOCK)){
        //0 lock
        //TODO openLock function undefine replace qDebug
        qDebug() << "QHLCMD_USART_OPEN_0_LOCK";
        receiveString.clear();
    }else if(receiveString.contains(QHLCMD_USART_OPEN_1_LOCK)){
         //1 lock
        qDebug() << "QHLCMD_USART_OPEN_1_LOCK";
         receiveString.clear();
    }else if(receiveString.contains(QHLCMD_USART_OPEN_2_LOCK)){
         //2 lock
         qDebug() << "QHLCMD_USART_OPEN_2_LOCK";
         receiveString.clear();
    }

    /*four lock mode*/
    if(receiveString.contains(QHLCMD_USART_OPEN_11_LOCK)){
        //11 lock
         qDebug() << "QHLCMD_USART_OPEN_11_LOCK";
         receiveString.clear();
    }else if(receiveString.contains(QHLCMD_USART_OPEN_12_LOCK)){
         //12 lock
         qDebug() << "QHLCMD_USART_OPEN_12_LOCK";
         receiveString.clear();
    }else if(receiveString.contains(QHLCMD_USART_OPEN_21_LOCK)){
         //21 lock
         qDebug() << "QHLCMD_USART_OPEN_21_LOCK";
         receiveString.clear();
    }else if(receiveString.contains(QHLCMD_USART_OPEN_31_LOCK)){
        //31 lock
         qDebug() << "QHLCMD_USART_OPEN_31_LOCK";
         receiveString.clear();
   }

}

