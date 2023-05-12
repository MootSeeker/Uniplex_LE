@echo off

for /f "delims=" %%t in ('git rev-list HEAD --count') do set count=%%t

echo Revision: %count%

echo #define REVISION %count% > ..\Core\Inc\revision.h
