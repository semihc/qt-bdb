#ifndef DBT_CALLBACK_HPP
#define DBT_CALLBACK_HPP

/** \file DbstlCallback.hpp
 * Declarations for DbstlCallback function templates.
 *
 * (c) Copyright Semih Cemiloglu
 * All rights reserved, see COPYRIGHT file for details.
 *
 * $Id$
 *
 */

#include <string.h>
#include <QByteArray>
#include <QDataStream>


template <typename T>
void CallbackCopy(void *dst, const T& obj)
{
  QByteArray ba;
  QDataStream ds(&ba, QIODevice::WriteOnly);
  // Serialize the object
  ds << obj;
  memcpy(dst, ba.data(), ba.size());
}

template <typename T>
void CallbackRestore(T& obj, void *dst)
{
  QByteArray ba = QByteArray::fromRawData((const char*)dst, sizeof(T));
  QDataStream ds(&ba, QIODevice::ReadOnly);
  // Reconstruct the object
  ds >> obj;
}
                  
template <typename T>
size_t CallbackSize(const T& obj)
{
  QByteArray ba;
  QDataStream ds(&ba, QIODevice::WriteOnly);
  // Serialize the object
  ds << obj;
  return ba.size();
}




#endif
