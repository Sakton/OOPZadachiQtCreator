TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        account.cpp \
        bankaccount.cpp \
        codeaccount.cpp \
        dateaccount.cpp \
        family.cpp \
        main.cpp \
        numberaccount.cpp \
        procent.cpp \
        summaccount.cpp

HEADERS += \
	abstract_save_open_class.h \
	account.h \
	bankaccount.h \
	codeaccount.h \
	dateaccount.h \
	family.h \
	numberaccount.h \
	procent.h \
	summaccount.h

DISTFILES += \
	Files/input
