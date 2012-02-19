#ifndef QDB_TEST_RUNNER_HH
#define QDB_TEST_RUNNER_HH

#include <QObject>
#include <QList>
#include <QVector>
#include <QStringList>

// FORWARDS
class QByteArray;


class TestRunner: public QObject
{
  Q_OBJECT

  public:
  // CREATORS
  TestRunner(const QStringList& args)
      : m_args(args) {}

  // MODIFIERS
  void setArgs(const QStringList& args)
  { m_args = args; }
                                               
  private slots:
  void test();

 protected:
  static void Args2Argv(const QStringList& args,
                        QList<QByteArray>& argl,
                        QVector<char*>& argv);

 private:
  QStringList m_args;

};

#endif
