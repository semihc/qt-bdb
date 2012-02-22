#
# Necessary environment variables to work QmkBld based projects
#

# If Projects Home directory is not defined
if [ -z "$PRJS_HOME" ]; then
  PRJS_HOME=$HOME
fi

# QmkBld related variables
QMKBLD=$HOME/qmkbld
QMK_DEBUG=0
QMAKEFEATURES=$QMKBLD/prf
export QMKBLD QMK_DEBUG QMAKEFEATURES

# The project that uses QmkBld 
export PRJ_ROOT=$HOME/qt-bdb

# Berkeley DB root directory
export PRJ_BDB=$PRJ_ROOT/bdb

export LD_LIBRARY_PATH=$PRJ_BDB/lib:$LD_LIBRARY_PATH

# Give feedback about project directories
echo "PRJ_ROOT=$PRJ_ROOT"
echo "PRJ_BDB=$PRJ_BDB"
