@echo off
REM construct app path, simple replace `\` to `\\`
set appPath=%~dp0TaskbarKiller-v2.exe
set appPath=%appPath:\=\\%
REM write file
set fileName="start.reg"
echo Windows Registry Editor Version 5.00>>%fileName%
echo [HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Run]>>%fileName%
echo "TaskbarKiller-v2"="%appPath%">>%fileName%