TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        abstractculture.cpp \
        fabriqueculture.cpp \
        main.cpp \
        ogorod.cpp

HEADERS += \
	abstractculture.h \
	fabriqueculture.h \
	ogorod.h
