TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        currency.cpp \
        dollar.cpp \
        euro.cpp \
        main.cpp

HEADERS += \
	currency.h \
	dollar.h \
	euro.h
