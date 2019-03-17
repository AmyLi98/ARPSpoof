#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <winsock2.h>
#include <iphlpapi.h>
#include <iostream>
#include <QDebug>
#include "arpsendthread.h"
#include "arprecvthread.h"
#include "updatemacthread.h"
#include "arpattackthread.h"
#include "buttonlist.h"

using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void getAllAdapterInfo();
    void fillAdapterInfo();

signals:
    void stopScan();

private slots:
    void on_scanButton_clicked();

    void on_stopButton_clicked();

    void on_clearButton_clicked();

    void on_updateButton_clicked();

private:
    Ui::Widget *ui;
    WSADATA mWasData;//winsock必须进行初始化
    // 网卡信息列表
    QList<QMap<QString,QString>> mAdapterList;
    // 网卡名称，IP->设备名称
    QMap<QString,QString> mAdapterName;
    // ARP发送报文线程
    ArpSendThread* mArpSendThread;
    // ARP接收报文线程
    ArpRecvThread* mArpRecvThread;
    // 厂商MAC地址处理线程
    UpdateMacThread* mUpdateMacThread;
    // ARP攻击线程
    ArpAttackThread* mArpAttackThread;

    // 下载厂商MAC地址文件
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    QFile *file;
    bool httpRequestAborted;

    // 记录扫描到的网卡数量
    int mMacNum = 0;
};

#endif // WIDGET_H
