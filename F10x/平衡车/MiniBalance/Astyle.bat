set astyle="D:\Program Files\AStyle\Astyle.exe"

REM 循环遍历目录

for /r . %%a in (*.c) do %astyle% --style=ansi -n "%%a"

for /r . %%a in (*.h) do %astyle% --style=ansi -n "%%a"

REM 删除所有的astyle生成文件

for /r . %%a in (*.orig) do del "%%a"

pause
