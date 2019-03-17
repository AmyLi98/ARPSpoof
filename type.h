#ifndef TYPE_H
#define TYPE_H
#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <QDebug>
#define HAVE_REMOTE
#include "pcap.h"

// 以太网首部 12byte
typedef struct _ethhead{
    // 以太网目地址 6byte
    uint8_t destEthAddr[6];
    // 以太网源地址 6byte
    uint8_t srcEthAddr[6];
    // 帧类型 2byte ,ARP请求或应答
    uint16_t frameType;
}eth_header;

// ARP请求和应答数据结构 28byte
typedef struct _arpstruct{
    // 硬件地址类型，1 表示以太网地址
    uint16_t hardType;
    // 映射的协议地址类型，0x0800 表示IP地址
    uint16_t protocolType;
    // 硬件地址长度
    uint8_t hardLen;
    // 协议地址长度
    uint8_t protocolLen;
    // 操作字段，ARP请求 1，ARP 应答 2，RARP请求 3，RARP应答 4
    uint16_t op;
    // 发送到以太网地址
    uint8_t srcEthAddr[6];
    // 发送端IP地址
    uint8_t srcIpAddr[4];
    // 目的端以太网地址
    uint8_t destEthAddr[6];
    // 目的端IP地址
    uint8_t destIpAddr[4];
}ArpStruct;

// 以太网ARP请求或应答数据包 结构 42byte
typedef struct _arppackage{
    eth_header ethHead;
    ArpStruct arpBody;
}ArpPackage;


/* 将数字类型的IP地址转换成字符串类型的 */
#define IPTOSBUFFERS    12
char *iptos(u_long in);

#endif // TYPE_H
