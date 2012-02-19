#ifndef DBT_INSERTER_HPP
#define DBT_INSERTER_HPP

/** \file DbtInserter.hpp
 * Declarations for the class template OpFsm.
 *
 * (c) Copyright Semih Cemiloglu
 * All rights reserved, see COPYRIGHT file for details.
 *
 * $Id$
 *
 */

#include <db_cxx.h>
#include <QByteArray>
#include <QDataStream>

template <typename T>
void operator<<(Dbt& dbt, const T& obj)
{
  QByteArray ba;
  QDataStream ds(&ba, QIODevice::WriteOnly);

  // Serialize the object
  ds << obj;

  dbt.set_ulen(ba.size());
  dbt.set_data(ba.data());
}


template <typename T>
void operator>>(const Dbt& dbt, T& obj)
{
  QByteArray ba = QByteArray::fromRawData((const char*)dbt.get_data(),
                                          dbt.get_ulen());
  QDataStream ds(&ba, QIODevice::ReadOnly);

  // Reconstruct the object
  ds >> obj;
}



#endif
