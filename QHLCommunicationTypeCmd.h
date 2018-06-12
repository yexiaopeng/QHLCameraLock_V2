#ifndef QHLCOMMUNICATIONTYPECMD_H
#define QHLCOMMUNICATIONTYPECMD_H


//向开锁器发送设备启动完成指令
#define QHLCMD_USART_DEVICE_STARTUP_OVERED "QHLStartUpOvered"

//接收的开锁器指令 四把锁模式
#define QHLCMD_USART_OPEN_11_LOCK  "pleaseopen11lock"  //1号柜前门
#define QHLCMD_USART_OPEN_12_LOCK  "pleaseopen12lock"  //1号柜后门
#define QHLCMD_USART_OPEN_21_LOCK  "pleaseopen21lock"  //2号柜前门
#define QHLCMD_USART_OPEN_31_LOCK  "pleaseopen31lock"  //3号柜前门
//接收的开锁器指令 三把锁模式
#define QHLCMD_USART_OPEN_0_LOCK   "pleaseopen0lock"   //前门
#define QHLCMD_USART_OPEN_1_LOCK   "pleaseopen1lock"   //后门
#define QHLCMD_USART_OPEN_2_LOCK   "pleaseopen2lock"   //右门



#endif // QHLCOMMUNICATIONTYPECMD_H

