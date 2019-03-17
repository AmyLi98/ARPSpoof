#ifndef ARPATTACKTHREAD_H
#define ARPATTACKTHREAD_H

#include <QObject>
#include <QThread>
#include "type.h"
#include "utils.h"
#define HAVE_REMOTE
#include "pcap.h"
#include "remote-ext.h"

class ArpAttackThread : public QThread
{
    Q_OBJECT
public:
    //在构造函数前面加explicit关键字，就能阻止编译器使用这个构造函数做隐式转换
    explicit ArpAttackThread(QObject *parent = nullptr);
    ArpAttackThread(uint32_t atkIPAddr,uint8_t* atkMacAddr,uint32_t curIPAddr,uint32_t broadcastAddr,uint32_t networkAddr,const uint8_t* macAddr,QString adapterName,QObject *parent = nullptr);

signals:
    void stopDone();//停止信号

public slots:
    void stopAttack();

public:
    void run();

private:
    // 当前IP
    uint32_t mCurIPAddr;
    // 当前物理地址
    uint8_t mCurMacAddr[6] = {0};
    // 广播地址
    uint32_t mBroadcastAddr;
    // 网络地址
    uint32_t mNetworkAddr;

    // 攻击的IP地址
    uint32_t mAtkIPAddr;
    // 攻击的物理地址
    uint8_t mAtkMacAddr[6] = {0};

    // 网卡设备 句柄
    pcap_t *mAdapterHandle = nullptr;
    // 停止攻击 标志
    bool isAttack = true;
};

#endif // ARPATTACKTHREAD_H
