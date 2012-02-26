include( $$(QMKBLD)/root.pri )

QT -= gui
TEMPLATE = app
CONFIG  += qtestlib 

TARGET = test_qdb
DESTDIR = $$PRJ_BIN


win32 {
 #INCLUDEPATH += $$PRJ_BDB_LANG/sql/generated
 LIBS += $$PRJ_BDB_LIB/libdb_sql53d.lib $$PRJ_BDB_LIB/libdb_stl53d.lib $$PRJ_BDB_LIB/libdb53d.lib
 DEFINES -= UNICODE
}
else {
 LIBS += -L$$PRJ_BDB/lib -ldb_sql $$PRJ_BDB/lib/libdb_stl.a -ldb_cxx -ldb
}


# Input
HEADERS += TestRunner.hh
SOURCES += TestRunner.cc
