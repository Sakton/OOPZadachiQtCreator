TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bankomat34b.cpp \
        bankomatbase.cpp \
        bankomatprivate.cpp \
        bankomatpublic.cpp \
        main.cpp

HEADERS += \
    bankomat34b.h \
    bankomatbase.h \
    bankomatprivate.h \
    bankomatpublic.h
