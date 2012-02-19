include( $$(QMKBLD)/root.pri )
QT -= gui
TEMPLATE = lib
CONFIG += static
TARGET = qt-bdb
DESTDIR = $$PRJ_LIB
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += DbtInserter.hpp DbstlCallback.hpp DbstlUtils.hh
SOURCES += DbstlUtils.cc


