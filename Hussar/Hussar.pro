#-------------------------------------------------
#
# Project created by QtCreator 2013-11-15T18:13:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hussar
TEMPLATE = app


SOURCES += main.cpp\
        hussarwindow.cpp \
        hussarcommandlineedit.cpp \
        hussarsession.cpp \
    hussarjobview.cpp \
    hussarjobhistoryscroll.cpp \
    hussarjobhistoryplane.cpp

HEADERS  += \
      hussarwindow.h \
      hussarcommandlineedit.h \
      hussarsession.h \
    hussarjobview.h \
    hussarjobhistoryscroll.h \
    hussarjobhistoryplane.h

FORMS    +=

RESOURCES += \
    hussar.qrc

OTHER_FILES += \
    hussar.qss
