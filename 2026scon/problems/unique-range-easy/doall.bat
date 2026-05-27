@echo off
rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
echo.
md tests
echo Generating answer for test #1
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""
echo.
echo Generating answer for test #2
call scripts\gen-answer.bat tests\02 tests\02.a "tests" ""
echo.
echo Generating answer for test #3
call scripts\gen-answer.bat tests\03 tests\03.a "tests" ""
echo.
echo Generating answer for test #4
call scripts\gen-answer.bat tests\04 tests\04.a "tests" ""
echo.
echo Generating answer for test #5
call scripts\gen-answer.bat tests\05 tests\05.a "tests" ""
echo.
echo Generating answer for test #6
call scripts\gen-answer.bat tests\06 tests\06.a "tests" ""
echo.
echo Generating answer for test #7
call scripts\gen-answer.bat tests\07 tests\07.a "tests" ""
echo.
echo Generating answer for test #8
call scripts\gen-answer.bat tests\08 tests\08.a "tests" ""
echo.
echo Generating answer for test #9
call scripts\gen-answer.bat tests\09 tests\09.a "tests" ""
echo.
echo Generating answer for test #10
call scripts\gen-answer.bat tests\10 tests\10.a "tests" ""
echo.

