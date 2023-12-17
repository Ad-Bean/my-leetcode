@echo off
REM 检查输入参数是否足够
IF "%1"=="" (
    goto :eof
)

IF "%2"=="" (
    echo %2
    goto :eof
)

set folder_name=%1
set file_name=%2

cd %folder_name%

IF EXIST %file_name% (
    echo %file_name%.cpp already exists
) ELSE (
    mkdir %file_name%
    cd %file_name%
    IF EXIST %file_name%.cpp (
        echo %file_name%.cpp already exists
    ) ELSE (
        echo. > %file_name%.cpp
    )
)

