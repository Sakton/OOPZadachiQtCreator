TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        account32.cpp \
        accountprivate.cpp \
        accountpublic.cpp \
        baseaccount.cpp \
        main.cpp

HEADERS += \
	account32.h \
	accountprivate.h \
	accountpublic.h \
	baseaccount.h
