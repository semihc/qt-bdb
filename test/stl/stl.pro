
include( $$(QMKBLD)/root.pri )

QT -= gui
TEMPLATE = app
CONFIG  += qtestlib 

TARGET = test_stl
DESTDIR = $$PRJ_BIN

win32 {
 LIBS += $$PRJ_BDB_LIB/libdb_stl53d.lib $$PRJ_BDB_LIB/libdb53d.lib
 SOURCES += $$PRJ_BDB_SRC/clib/getopt.c
 DEFINES -= UNICODE
}
else {
 # unix
 LIBS += $$PRJ_BDB_LIB/libdb_stl.a -ldb_cxx -ldb
}



# Input
HEADERS += StlAdvancedFeatures.h TestRunner.hh
SOURCES += StlAccessExample.cpp \
           StlAdvancedFeatures.cpp \
           StlTpcbExample.cpp \
           StlTransactionGuideExample.cpp \
           TestRunner.cc
