set astyle="D:\Program Files\AStyle\Astyle.exe"

REM ѭ������Ŀ¼

for /r . %%a in (*.c) do %astyle% --style=ansi -n "%%a"

for /r . %%a in (*.h) do %astyle% --style=ansi -n "%%a"

REM ɾ�����е�astyle�����ļ�

for /r . %%a in (*.orig) do del "%%a"

pause
