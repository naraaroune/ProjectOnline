#-------------------------------------------------
#
# Project created by QtCreator 2014-07-13T22:01:20
#
#-------------------------------------------------

QT       += core gui
QT      +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectOnline
TEMPLATE = app
RC_FILE = icone.rc
INCLUDEPATH += libmysql.dll

SOURCES += main.cpp\
        mainwindow.cpp \
    ftp.cpp \
    inscriptionwindow.cpp \
    md5.cpp \
    modifierpassword.cpp \
    modifierwindow.cpp \
    User.cpp

HEADERS  += mainwindow.h \
    ftp.h \
    inscriptionwindow.h \
    md5.h \
    modifierpassword.h \
    modifierwindow.h \
    qdatetime.h \
    ui_inscriptionwindow.h \
    ui_mainwindow.h \
    ui_modifierpassword.h \
    ui_modifierwindow.h \
    User.h

FORMS    += mainwindow.ui\
    inscriptionwindow.ui \
    modifierpassword.ui \
    modifierwindow.ui

