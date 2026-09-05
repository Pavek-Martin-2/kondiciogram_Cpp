cls
@echo off

REM vytvori dnesni datum jako parametr 2
set dat=%DATE%
echo %dat%

set d=%dat:~0,2%
echo %d%

set m=%dat:~3,2%
echo %m%

set r=%dat:~6,4%
echo %r%

set dnes=%d%%m%%r%
echo %dnes%

kondiciogram 28031971 %dnes%
REM tady si upravit datum 28031971 za svoje, jinak nechat jak je








