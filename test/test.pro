QT += testlib core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_spaceshootertest.cpp \
            ../src/sprite.cpp
            ../src/game.cpp

HEADERS += ../src/sprite.h \
           ../src/game.h

INCLUDEPATH += ../src
