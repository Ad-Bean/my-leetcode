@echo off
REM 检查输入参数是否足够
if "%1"=="" (
    goto :eof
)

if "%2"=="" (
    echo %2
    goto :eof
)

REM 
set folder_name=%1
set file_name=%2

REM 
cd %folder_name%

mkdir %file_name%
cd %file_name%

REM 
echo. > %file_name%.cpp

