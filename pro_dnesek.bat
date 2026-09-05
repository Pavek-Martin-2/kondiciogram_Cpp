cls
@echo off

set /p narozeni="zadej datum narozeni DDMMRRRR : "
echo %narozeni%

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
echo %dnes%

kondiciogram %narozeni% %dnes%






