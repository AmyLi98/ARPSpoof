#ifndef ARPACCEPTTHREAD_H
#define ARPACCEPTTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include "type.h"
#include "utils.h"
#define HAVE_REMOTE
#include "pcap.h"
#include "remote-ext.h"

/* MAC地址扫描器的ARP接收报文线程 */
class ArpRecvThread : public QThread
{
    Q_OBJECT
private:
    // 网卡设备 句柄
    pcap_t *mAdapterHandle = nullptr;
    // 是否接受包 标志
    bool isAccept = true;
    // 本机IP
    QString mIP;

public:
    explicit ArpRecvThread(QObject *parent = nullptr);
    ArpRecvThread(QString adapterName,QString ip);
    ~ArpRecvThread(){
        qDebug() << "ArpAcceptThread 析构函数";
    };
    void run();

signals:
    // 接受到ARP应答包 信号
    void recvArp(QMap<QString,QString> info);
    // 接受完毕 信号
    void recvDone();

public slots:
    // 停止接受ARP包 槽函数
    void stopRecv();
};

#endif // ARPACCEPTTHREAD_H
