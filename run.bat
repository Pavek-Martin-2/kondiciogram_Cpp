@echo off
title run.bat
@echo dnes je: 
date /t

set /p narozeni="zadej datum narozeni DDMMRRRR : "
echo %narozeni%

set /p cilove="zadej cilove datum DDMMRRRR : "
echo %cilove%

kondiciogram %narozeni% %cilove%




