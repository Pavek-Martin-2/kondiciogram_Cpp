cls
@echo off

REM set /p narozeni="zadej datum narozeni DDMMRRRR : "
REM echo %narozeni%

REM vytvori dnesni datum jako parametr 2
set dat=%DATE%
REM echo %dat%

set d=%dat:~0,2%
REM echo %d%

set m=%dat:~3,2%
REM echo %m%

set r=%dat:~6,4%
REM echo %r%

set dnes=%d%%m%%r%
REM echo %dnes%

kondiciogram 28031971 %dnes%
REM tady si upravit datum 28031971 za svoje, jinak nechat jak je








