include( $$(QMKBLD)/root.pri )

QT -= gui
TEMPLATE = app
CONFIG  += qtestlib 

TARGET = test_sql
DESTDIR = $$PRJ_BIN

LIBS += -L$$PRJ_BDB/lib -ldb_sql -ldb


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
