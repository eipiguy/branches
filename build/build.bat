@echo off

rem Returns the following error codes in top to bottom priority:
rem 1 = configuration failure
rem 2 = build failure
rem 3 = directory doesn't exist
rem 4 = directory doesn't have a CMake file

set sourceDir=%1
set buildDir=%2

if [ %sourceDir%=="" ] (
    set sourceDir="%CD%/../source"
)
if not exist "%sourceDir%" (
    echo "Source directory '%sourceDir%' does not exist!"
    echo "returning..."
    pause
    exit /b 3
)
if not exist "%sourceDir%/CMakeLists.txt" (
    echo "Source directory '%sourceDir%' does not have a CMake file!"
    echo "returning..."
    pause
    exit /b 4
)

if [ %buildDir%=="" ] (
    set buildDir="%sourceDir%/../build"
)
if not exist "%buildDir%" (
    echo "Build directory '%buildDir%' does not exist!"
    echo "returning..."
    pause
    exit 3
)

rem Configure
cmake -S %sourceDir% -B %buildDir%/windows

rem Build
cmake --build %buildDir%/windows

pause
exit /b 0