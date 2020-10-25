TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        basetime.cpp \
        main.cpp \
        time30.cpp \
        timeprivate.cpp \
        timepublic.cpp

HEADERS += \
	basetime.h \
	time30.h \
	timeprivate.h \
	timepublic.h
