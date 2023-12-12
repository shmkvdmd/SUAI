QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    messageform.cpp \
    registrationform.cpp \
    searchform.cpp \
    user.cpp \
    usermainform.cpp \
    usermanager.cpp

HEADERS += \
    DatabaseManager.h \
    Includes.h \
    loginform.h \
    mainwindow.h \
    messageform.h \
    registrationform.h \
    searchform.h \
    user.h \
    usermainform.h \
    usermanager.h

FORMS += \
    loginform.ui \
    mainwindow.ui \
    messageform.ui \
    registrationform.ui \
    searchform.ui \
    usermainform.ui

RC_FILE = file.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
