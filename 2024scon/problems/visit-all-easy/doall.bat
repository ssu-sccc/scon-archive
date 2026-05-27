@echo off
rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
echo Generating test #2
call scripts\gen-input-via-stdout.bat "files\all-gen.exe ""-N=99""" "tests\02" 2
echo Generating test #3
call scripts\gen-input-via-stdout.bat "files\all-gen.exe ""-N=100""" "tests\03" 3
echo Generating test #4
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""-N=1000000000""" "tests\04" 4
echo Generating test #5
call scripts\gen-input-via-stdout.bat "files\gen-small-all.exe ""-mx=9""" "tests\05" 5
echo Generating test #7
call scripts\gen-input-via-stdout.bat "files\gen-small-all.exe ""-mx=31""" "tests\07" 7
echo.
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

