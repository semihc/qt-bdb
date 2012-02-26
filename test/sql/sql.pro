include( $$(QMKBLD)/root.pri )

QT -= gui
TEMPLATE = app
CONFIG  += qtestlib 

TARGET = test_sql
DESTDIR = $$PRJ_BIN

win32 {
 INCLUDEPATH += $$PRJ_BDB_LANG/sql/generated
 LIBS += $$PRJ_BDB_LIB/libdb_sql53d.lib $$PRJ_BDB_LIB/libdb53d.lib
 DEFINES -= UNICODE
}
else {
 LIBS += -L$$PRJ_BDB/lib -ldb_sql -ldb
}


datafiles.path = $$PRJ_BIN
datafiles.files = country.csv sms.csv university.csv
INSTALLS += datafiles

# Input
HEADERS += ex_sql_utils.h TestRunner.hh
SOURCES += ex_sql_binding.c \
           ex_sql_index.c \
           ex_sql_load.c \
           ex_sql_multi_thread.c \
           ex_sql_query.c \
           ex_sql_savepoint.c \
           ex_sql_statement.c \
           ex_sql_transaction.c \
           ex_sql_utils.c \
           TestRunner.cc
