#include <QtTest/QtTest>

#include "TestRunner.hh"

#include <QString>
#include <QList>

using namespace std;

extern "C" {
int sql_load_main();
int sql_index_main();
int sql_query_main();
int sql_statement_main();
int sql_transaction_main();
int sql_binding_main();
int sql_savepoint_main();
int sql_mt_main();
}


void TestRunner::Args2Argv(const QStringList& args,
                           QList<QByteArray>& argl,
                           QVector<char*>& argv)
{
  int i;

  argl.clear();
  argv.clear();
    
  for(i=0; i<args.size(); ++i)
    argl.push_back(args.at(i).toAscii());

  for(i=0; i<argl.size(); ++i) 
    argv.push_back(argl[i].data());
}


void TestRunner::load()
{
  QList<QByteArray> argl;
  QVector<char*> argv;
  
  qDebug() << "Calling sql_load_main() with args" << m_args.join(" ");
  Args2Argv(m_args, argl, argv);

  int rv = sql_load_main();
  QVERIFY(0==rv);
}


void TestRunner::index()
{
  QList<QByteArray> argl;
  QVector<char*> argv;
  
  qDebug() << "Calling sql_index_main() with args" << m_args.join(" ");
  Args2Argv(m_args, argl, argv);

  int rv = sql_index_main();
  QVERIFY(0==rv);
}


void TestRunner::query()
{
  QList<QByteArray> argl;
  QVector<char*> argv;
  
  qDebug() << "Calling sql_query_main() with args" << m_args.join(" ");
  Args2Argv(m_args, argl, argv);

  int rv = sql_query_main();
  QVERIFY(0==rv);
}


void TestRunner::statement()
{
  QList<QByteArray> argl;
  QVector<char*> argv;
  
  qDebug() << "Calling sql_statement_main() with args" << m_args.join(" ");
  Args2Argv(m_args, argl, argv);

  int rv = sql_statement_main();
  QVERIFY(0==rv);
}


void TestRunner::transaction()
{
  QList<QByteArray> argl;
  QVector<char*> argv;
  
  qDebug() << "Calling sql_transaction_main() with args" << m_args.join(" ");
  Args2Argv(m_args, argl, argv);

  int rv = sql_statement_main();
  QVERIFY(0==rv);
}


void TestRunner::binding()
{
  QList<QByteArray> argl;
  QVector<char*> argv;
  
  qDebug() << "Calling sql_binding_main() with args" << m_args.join(" ");
  Args2Argv(m_args, argl, argv);

  int rv = sql_binding_main();
  QVERIFY(0==rv);
}


void TestRunner::savepoint()
{
  QList<QByteArray> argl;
  QVector<char*> argv;
  
  qDebug() << "Calling sql_savepoint_main() with args" << m_args.join(" ");
  Args2Argv(m_args, argl, argv);

  int rv = sql_savepoint_main();
  QVERIFY(0==rv);
}

void TestRunner::mt()
{
  QList<QByteArray> argl;
  QVector<char*> argv;
  
  qDebug() << "Calling sql_mt_main() with args" << m_args.join(" ");
  Args2Argv(m_args, argl, argv);

  int rv = sql_mt_main();
  QVERIFY(0==rv);
}


//QTEST_MAIN(TestRunner) 

int main(int argc, char* argv[])
{
  QCoreApplication app(argc, argv);
  QStringList args = QCoreApplication::arguments();

  QStringList tr_args;
  QStringList qt_args;
  QString s;

  // Copy over the first argument which is program name
  s = args.at(0);
  tr_args.push_back(s);
  qt_args.push_back(s);

  QStringList* dest_args = &qt_args;
  for(int i=1; i<args.size(); ++i) {
    s = args[i];
    if(s=="--")  { // if -- is specified then 
      dest_args = &tr_args; // destination args is tr_args
      continue;
    }
    dest_args->push_back(s);
  }

  // qDebug() << args.join(",");
  // qDebug() << "qt" << qt_args.join(",");
  // qDebug() << "tr" << tr_args.join(",");
  
  TestRunner tr(tr_args);
  int rv;

  rv = QTest::qExec(&tr, qt_args);

  return rv;
}
