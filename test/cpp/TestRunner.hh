#ifndef CPP_TEST_RUNNER_HH
#define CPP_TEST_RUNNER_HH

#include <QObject>
#include <QStringList>

// FORWARDS
class QStringList;


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
  void load();
  void read();


 private:
  QStringList m_args;

};

#endif
