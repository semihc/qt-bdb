rem
rem This batch file should be run after setting
rem Visual C++ environment variables are set
rem

rem Berkeley DB version
set DB=db-5.3.15

rem Delete the files
del /s /q /f %DB%

rem Delete the directory
rmdir /s /q %DB%

rem Unpack
rem tar xzvpf %DB%.tar.gz
unzip %DB%.zip

rem Build
cd %DB%\build_windows
vcbuild.exe -M3 Berkeley_DB.sln
cd ..\..

