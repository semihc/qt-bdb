include( $$(QMKBLD)/root.pri )

QT -= gui
TEMPLATE = app
CONFIG  += qtestlib 

TARGET = test_cpp
DESTDIR = $$PRJ_BIN

win32 {
 LIBS += $$PRJ_BDB_LIB/libdb53d.lib
 SOURCES += $$PRJ_BDB_SRC/clib/getopt.c
 DEFINES -= UNICODE
}
else {
 LIBS += -L$$PRJ_BDB/lib -ldb_cxx -ldb
}

datafiles.path = $$PRJ_BIN
datafiles.files = inventory.txt vendors.txt
INSTALLS += datafiles

# Input
HEADERS += gettingStartedCommon.hpp MyDb.hpp TestRunner.hh
SOURCES += db_load.cpp db_read.cpp MyDb.cpp TestRunner.cc
