TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        account32.cpp \
        account32private.cpp \
        main.cpp \
        money24.cpp

HEADERS += \
	account32.h \
	account32private.h \
	money24.h
