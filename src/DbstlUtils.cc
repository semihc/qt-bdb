
#include <string.h>

#include <QByteArray>
#include <QString>

#include <db_cxx.h>
#include <dbstl_utility.h>

#include "DbstlUtils.hh"
#include "DbstlCallback.hpp"
#include "DbtInserter.hpp"


using namespace dbstl;

// Template instantiations
template void operator<<(Dbt& dbt, const QByteArray& obj);
template void operator>>(const Dbt& dbt, QByteArray& obj);

template void CallbackCopy(void *dst, const QString& obj);
template void CallbackRestore(QString& obj, void *dst);
template size_t CallbackSize(const QString& obj);


void QByteArrayCopy(void *dst, const QByteArray& obj)
{
  memcpy(dst, obj.data(), obj.size());
}

void QByteArrayRestore(QByteArray& dst, const void *src)
{
  dst = QByteArray(static_cast<const char*>(src));
}

size_t QByteArraySize(const QByteArray& obj)
{
  return obj.size();
}


