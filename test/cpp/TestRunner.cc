#include <QtTest/QtTest>

#include "TestRunner.hh"

#include <QString>
#include <QStringList>
#include <QList>
#include <QVector>

using namespace std;


int db_load_main(int argc, char *argv[]);
int db_read_main(int argc, char *argv[]);


void TestRunner::load()
{
  QList<QByteArray> list;
  int i;

  qDebug() << "Calling db_load_main() with args" << m_args.join(" ");
  for(int i=0; i<m_args.size(); ++i)
    list.push_back(m_args.at(i).toLatin1());

  QVector<char*> argvec;
  for(i=0; i<list.size(); ++i) 
    argvec.push_back(list[i].data());

  int rv = db_load_main(argvec.size(), argvec.data());
  QVERIFY(0==rv);
}


void TestRunner::read()
{
  QList<QByteArray> list;
  int i;

  qDebug() << "Calling db_read_main() with args" << m_args.join(" ");
  for(int i=0; i<m_args.size(); ++i) 
    list.push_back(m_args.at(i).toLatin1());

  QVector<char*> argvec;
  for(i=0; i<list.size(); ++i) 
    argvec.push_back(list[i].data());

  int rv = db_read_main(argvec.size(), argvec.data());
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
