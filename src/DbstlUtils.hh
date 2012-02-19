#ifndef DBSTLUTILS_HH
#define DBSTLUTILS_HH

/** \file DbstlUtils.hh
 * Dbstl related utilities.
 *
 * (c) Copyright Semih Cemiloglu
 * All rights reserved, see COPYRIGHT file for details.
 *
 * $Id$
 *
 */

// FORWARDS
class QByteArray;
class QString;



void QByteArrayCopy(void *dst, const QByteArray& obj);
void QByteArrayRestore(QByteArray& dst, const void *src);
size_t QByteArraySize(const QByteArray& obj);


#endif
