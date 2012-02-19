#
#
DB=db-5.3.15
PWD=`pwd`
CMD="rm -fr ${DB} bin lib include docs"
$CMD
CMD="tar xzvpf ${DB}.tar.gz"
$CMD
cd $DB/build_windows

vcbuild.exe -M3 Berkeley_DB.sln

cd ../..
cmd /c "mklink /j include "db-5.3.15/build_windows""
cmd /c "mklink /j bin "db-5.3.15/build_windows/Win32/Debug""
cmd /c "mklink /j lib "db-5.3.15/build_windows/Win32/Debug""

#ln -s ${DB}/build_windows/Win32/Debug bin
#ln -s ${DB}/build_windows/Win32/Debug lib
#ln -s ${DB}/build_windows include

