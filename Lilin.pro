#-------------------------------------------------
#
# Project created by QtCreator 2019-09-02T10:41:04
#
#-------------------------------------------------

QT      += core gui
QT      += serialport



#QT      += webenginewidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lilin
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        basictransceiver.cpp \
        main.cpp

HEADERS += \
        basictransceiver.h

FORMS += \
        basictransceiver.ui

# Default rules for deployment.


RESOURCES += \
    basictransceiver.qrc


UI_DIR=./UI
RC_ICONS = huo.ico

