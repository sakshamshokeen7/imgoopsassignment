@echo off
REM Build script for imgoops project (Windows cmd)
SET OUT=app.exe
SET SRC=
for %%f in ("cpp files\*.cpp") do SET SRC=!SRC! "%%~ff"

g++ -std=c++17 -Iheaders -Wall -Wextra -g %SRC% "main.cpp" -o %OUT%
IF %ERRORLEVEL% EQU 0 (
  echo Build succeeded: %OUT%
) ELSE (
  echo Build failed with exit code %ERRORLEVEL%
)
