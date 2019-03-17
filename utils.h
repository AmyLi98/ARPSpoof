#ifndef UTILS_H
#define UTILS_H
#include <stdint.h>
#include <stdlib.h>
#include <QDebug>
#include "type.h"

class Utils
{
public:
    Utils();
    // 获取有效网卡的 ip -> 设备名称
    static QMap<QString,QString> geValidAdapter();

    // N字节本地字节序转为网络字节序 dest 为传出参数，需要用户提供空间，size 转换字节的长度
    static uint8_t* htonN(const uint8_t* parm, uint8_t *dest, uint32_t size);
    // N字节网络字节序转为本地字节序
    static uint8_t* ntohN(const uint8_t* parm, uint8_t *dest, uint32_t size);

    // 物理地址BYTE转HEX字符串 00-0C-56-2A-1B-DA
    static void macToHexString(const uint8_t* mac, char* hex);
    // HEX字符串 00-0C-56-2A-1B-DA 转物理地址BYTE
    static void hexToMacByte(const char* hex, uint8_t* mac);

private:
    static void ifprocess(pcap_if_t *d, QMap<QString,QString> *map);
};

#endif // UTILS_H
