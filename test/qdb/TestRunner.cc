#include <QtTest/QtTest>

#include "TestRunner.hh"

#include <QString>
#include <QList>

using namespace std;


void TestRunner::Args2Argv(const QStringList& args,
                           QList<QByteArray>& argl,
                           QVector<char*>& argv)
{
  int i;

  argl.clear();
  argv.clear();
    
  for(i=0; i<args.size(); ++i)
    argl.push_back(args.at(i).toLatin1());

  for(i=0; i<argl.size(); ++i) 
    argv.push_back(argl[i].data());
}


void TestRunner::test()
{
  QVERIFY(1);
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
