QT       += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/command.cpp \
    VM/commandvm.cpp \
    View/ModeSelector/ModeSelector.cpp \
    View/StateViewer/altitudeview.cpp \
    View/StateViewer/gpsstatusview.cpp \
    View/StateViewer/imuview.cpp \
    View/console/console.cpp \
    View/StateViewer/StateViewer.cpp \
    View/SerialConfigure.cpp \
    View/console/console_ready.cpp \
    View/console/counter.cpp \
    View/console/servo.cpp \
    View/console/setgoalview.cpp \
    cansat_command/CommandHandlerBase.cpp \
    cansat_command/CommandHandlers.cpp \
    cansat_command/CommandManager.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Model/command.h \
    VM/commandvm.h \
    View/ModeSelector/ModeSelector.hpp \
    View/StateViewer/altitudeview.h \
    View/StateViewer/gpsstatusview.h \
    View/StateViewer/imuview.h \
    View/console/console.hpp \
    View/StateViewer/StateViewer.hpp \
    View/SerialConfigure.hpp \
    View/console/console_ready.h \
    View/console/counter.h \
    View/console/servo.h \
    View/console/setgoalview.h \
    cansat_command/Inc/CommandDataType.hpp \
    cansat_command/Inc/CommandHandlerBase.h \
    cansat_command/Inc/CommandHandlers.hpp \
    cansat_command/Inc/CommandManager.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    cansat_command/.gitignore
