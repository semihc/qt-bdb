
include( $$(QMKBLD)/root.pri )

QT -= gui
TEMPLATE = app
CONFIG  += qtestlib 

TARGET = test_stl
DESTDIR = $$PRJ_BIN

unix:LIBS += -L$$PRJ_BDB/lib $$PRJ_BDB/lib/libdb_stl.a -ldb_cxx -ldb
win32:LIBS += -L$$PRJ_BDB/lib -ldb_stl -ldb_cxx -ldb



# Input
HEADERS += StlAdvancedFeatures.h TestRunner.hh
SOURCES += StlAccessExample.cpp \
           StlAdvancedFeatures.cpp \
           StlTpcbExample.cpp \
           StlTransactionGuideExample.cpp \
           TestRunner.cc
