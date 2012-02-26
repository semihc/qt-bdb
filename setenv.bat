@echo off

rem If Projects Home directory is not defined
if not defined PRJS_HOME (
  set PRJS_HOME=%HOME%
)

rem QmkBld related variables
set QMKBLD=%PRJS_HOME%\qmkbld
set QMK_DEBUG=0
set QMAKEFEATURES=%QMKBLD%\prf


rem The project that uses QmkBld 
set PRJ_ROOT=%PRJS_HOME%\qt-bdb

rem Berkeley DB root
set PRJ_BDB=$PRJ_ROOT\bdb

rem Give feedback about project root
@echo PRJ_ROOT=%PRJ_ROOT%
