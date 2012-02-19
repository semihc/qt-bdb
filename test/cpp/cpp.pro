include( $$(QMKBLD)/root.pri )

QT -= gui
TEMPLATE = app
CONFIG  += qtestlib 

TARGET = test_cpp
DESTDIR = $$PRJ_BIN

LIBS += -L$$PRJ_BDB/lib -ldb_cxx -ldb



# Input
HEADERS += gettingStartedCommon.hpp MyDb.hpp TestRunner.hh
SOURCES += db_load.cpp db_read.cpp MyDb.cpp TestRunner.cc
