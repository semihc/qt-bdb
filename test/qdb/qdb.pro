include( $$(QMKBLD)/root.pri )

QT -= gui
TEMPLATE = app
#CONFIG  += qtestlib 
QT  += testlib 

TARGET = test_qdb
DESTDIR = $$PRJ_BIN


win32 {
 #INCLUDEPATH += $$PRJ_BDB_LANG/sql/generated
 LIBS += $$PRJ_BDB_LIB/libdb_sql53d.lib $$PRJ_BDB_LIB/libdb_stl53d.lib $$PRJ_BDB_LIB/libdb53d.lib
 DEFINES -= UNICODE
}
else {
 LIBS += -ldb_sql $$PRJ_BDB_LIB/libdb_stl.a -ldb_cxx -ldb
}


# Input
HEADERS += TestRunner.hh
SOURCES += TestRunner.cc
