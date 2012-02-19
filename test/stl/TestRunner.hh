#ifndef STL_TEST_RUNNER_HH
#define STL_TEST_RUNNER_HH

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
  void access();
  void advanced();
  void tbc();
  void trans();

 protected:
  static void Args2Argv(const QStringList& args,
                        QList<QByteArray>& argl,
                        QVector<char*>& argv);

 private:
  QStringList m_args;

};

#endif
