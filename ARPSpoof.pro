#-------------------------------------------------
#
# Project created by QtCreator 2019-03-08T11:47:56
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ARPSpoof
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#INCLUDEPATH += D:\WinPcap\WpdPack\Include
#LIBS += D:\WinPcap\WpdPack\Lib\wpcap.lib
#LIBS += D:\WinPcap\WpdPack\Lib\Packet.lib
#LIBS += D:\WinPcap\WpdPack\Lib\libpacket.a
#LIBS += D:\WinPcap\WpdPack\Lib\libwpcap.a
LIBS += -lpthread libwsock32 libws2_32 libiphlpapi

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    arpattackthread.cpp \
    arpsendthread.cpp \
    buttonlist.cpp \
    updatemacthread.cpp \
    utils.cpp \
    type.cpp \
    arprecvthread.cpp

HEADERS += \
        widget.h \
    arpattackthread.h \
    arpsendthread.h \
    buttonlist.h \
    updatemacthread.h \
    utils.h \
    type.h \
    arprecvthread.h

FORMS += \
        widget.ui \
    buttonlist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ARPSpoof.pro

DISTFILES += \
    ARPSpoof.pro.user


win32:CONFIG(release, debug|release): LIBS += -LD:/WinPcap/WpdPack/Lib/x64/ -lwpcap
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/WinPcap/WpdPack/Lib/x64/ -lwpcap
else:unix: LIBS += -LD:/WinPcap/WpdPack/Lib/x64/ -lwpcap

INCLUDEPATH += D:/WinPcap/WpdPack/Include
DEPENDPATH += D:/WinPcap/WpdPack/Include

RC_ICONS = communication_messages.ico
