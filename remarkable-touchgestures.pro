######################################################################
# Automatically generated by qmake (3.0) Tue Apr 9 11:36:23 2019
######################################################################
system(./makeversion.sh) QMAKE_EXTRA_TARGETS += version.h
PRE_TARGETDEPS += version.h
QT = gui
TEMPLATE = app
DESTDIR = bin
OBJECTS_DIR = obj
TARGET = touchinjector
CONFIG   += c++11
INCLUDEPATH += .
QMAKE_CXXFLAGS_RELEASE = -fvisibility=hidden

# Input
SOURCES += *.cpp
SOURCES += *.c
HEADERS += *.h \
    config.h
# FB stuff
linux-oe-g++{
        LIBS += -lqsgepaper
        DEFINES += REMARKABLE
}
