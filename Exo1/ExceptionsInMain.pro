TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += testExceptionsInMain.cpp \
    CExceptions.cpp

HEADERS += \
    CExceptions.h \
    testExceptionsInMain.h \
    CstCodErr.h
