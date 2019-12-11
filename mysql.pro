QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addmoditem.cpp \
    bill.cpp \
    cart.cpp \
    confirmationmenu.cpp \
    controller.cpp \
    customer.cpp \
    dialog.cpp \
    employee.cpp \
    global.cpp \
    item.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    owner.cpp \
    person.cpp \
    store.cpp \
    storemenu.cpp \
    timestamp.cpp \
    user.cpp

HEADERS += \
    addmoditem.h \
    bill.h \
    cart.h \
    confirmationmenu.h \
    controller.h \
    customer.h \
    dialog.h \
    employee.h \
    global.h \
    item.h \
    login.h \
    mainwindow.h \
    menu.h \
    owner.h \
    person.h \
    store.h \
    storemenu.h \
    timestamp.h \
    user.h

FORMS += \
    addmoditem.ui \
    confirmationmenu.ui \
    dialog.ui \
    login.ui \
    mainwindow.ui \
    storemenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target







unix|win32: LIBS += -L$$PWD/'../../../../Program Files/MySQL/MySQL Server 8.0/lib/' -llibmysql

INCLUDEPATH += $$PWD/'../../../../Program Files/MySQL/MySQL Server 8.0/include'
DEPENDPATH += $$PWD/'../../../../Program Files/MySQL/MySQL Server 8.0/include'

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/'../../../../Program Files/MySQL/MySQL Server 8.0/lib/libmysql.lib'

RESOURCES += \
    resource.qrc

DISTFILES += \
    ../../Desktop/uOFNos.jpg

