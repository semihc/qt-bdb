include( $$(QMKBLD)/root.pri )

QT -= gui
TEMPLATE = app
CONFIG  += qtestlib 

TARGET = test_qdb
DESTDIR = $$PRJ_BIN

unix:LIBS += -L$$PRJ_BDB/lib -ldb_sql $$PRJ_BDB/lib/libdb_stl.a -ldb_cxx -ldb
win32:LIBS += -L$$PRJ_BDB/lib -ldb_sql -ldb_stl -ldb_cxx -ldb


# Input
HEADERS += TestRunner.hh
SOURCES += TestRunner.cc
