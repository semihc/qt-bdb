#
# Necessary environment variables to work QmkBld based projects
#

# QmkBld related variables
QMKBLD=$HOME/qmkbld
QMK_DEBUG=0
QMAKEFEATURES=$QMKBLD/prf
export QMKBLD QMK_DEBUG QMAKEFEATURES

# The project that uses QmkBld 
export PRJ_ROOT=$HOME/qt-bdb

# Berkeley DB root
export PRJ_BDB=$PRJ_ROOT/bdb

export LD_LIBRARY_PATH=$PRJ_BDB/lib:$LD_LIBRARY_PATH



