TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        basedate.cpp \
        date29.cpp \
        dateprivate.cpp \
        datepublic.cpp \
        main.cpp

HEADERS += \
	basedate.h \
	date29.h \
	dateprivate.h \
	datepublic.h
