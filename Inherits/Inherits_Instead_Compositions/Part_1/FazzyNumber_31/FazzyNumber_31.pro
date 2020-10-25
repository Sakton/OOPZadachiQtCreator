TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        basefuzzy.cpp \
        fussyprivate.cpp \
        fuzzupublic.cpp \
        fuzzynumber31.cpp \
        main.cpp

HEADERS += \
	basefuzzy.h \
	fussyprivate.h \
	fuzzupublic.h \
	fuzzynumber31.h
