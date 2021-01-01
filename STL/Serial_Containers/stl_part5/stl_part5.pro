TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        modificators_class.cpp

DISTFILES += \
	Files/input.txt \
	Files/output.txt

HEADERS += \
	modificators_class.h
