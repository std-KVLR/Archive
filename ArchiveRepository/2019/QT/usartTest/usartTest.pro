#-------------------------------------------------
#
# Project created by QtCreator 2019-01-26T15:21:53
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#VERSION = 0.1
#QMAKE_TARGET_COMPANY = KSIT IT571M z73114
##QMAKE_TARGET_PRODUCT = Angle Loader

RC_FILE = resources.rc

TARGET = AngleLoader
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mycom.cpp \
    FUNCTIONS/MathFunctions.cpp

HEADERS += \
        mainwindow.h \
    mycom.h \
    FUNCTIONS/MathFunctions.h

FORMS += \
        mainwindow.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc

DISTFILES += \
    resources.rc
