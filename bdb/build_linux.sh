#
#
DB=db-5.3.15
PWD=`pwd`
CFG_FLAGS="--prefix=${PWD} --enable-cxx --enable-stl --enable-sql --enable-sql_codegen"

CFG_DBG_FLAGS="--enable-debug --enable-diagnostic"
#Also condider these:
#--with-tcl=/usr/lib/tcl8.5 --enable-tcl --enable-test --enable-dtrace

CMD="rm -fr ${DB} bin lib include docs"
$CMD
CMD="tar xzvpf ${DB}.tar.gz"
$CMD
cd $DB/build_unix

CMD="../dist/configure ${CFG_FLAGS} ${CFG_DBG_FLAGS}"
echo $CMD
$CMD 2>&1 |tee conf.log
make 2>&1 |tee make.log
#make install 2>&1 |tee inst.log
make install_include install_lib install_utilities 2>&1 |tee inst.log
