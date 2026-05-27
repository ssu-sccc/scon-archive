@echo off
rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
echo Generating test #2
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-n=1""" "tests\02" 2
echo Generating test #3
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-n=2""" "tests\03" 3
echo Generating test #4
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-n=3""" "tests\04" 4
echo Generating test #5
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-l=10"" ""-r=8000"" ""0""" "tests\05" 5
echo Generating test #6
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-n=8192""" "tests\06" 6
echo Generating test #7
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-l=10"" ""-r=8000"" ""1""" "tests\07" 7
echo Generating test #8
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-n=8191""" "tests\08" 8
echo Generating test #9
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-l=10"" ""-r=8000"" ""2""" "tests\09" 9
echo Generating test #10
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-n=8190""" "tests\10" 10
echo Generating test #11
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-l=10"" ""-r=8000"" ""3""" "tests\11" 11
echo Generating test #12
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-n=8189""" "tests\12" 12
echo Generating test #13
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-l=10"" ""-r=8000"" ""4""" "tests\13" 13
echo Generating test #14
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-n=8188""" "tests\14" 14
echo Generating test #15
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-l=10"" ""-r=8000"" ""5""" "tests\15" 15
echo Generating test #16
call scripts\gen-input-via-stdout.bat "files\gen.exe ""-n=8187""" "tests\16" 16
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
echo Generating answer for test #8
call scripts\gen-answer.bat tests\08 tests\08.a "tests" ""
echo.
echo Generating answer for test #9
call scripts\gen-answer.bat tests\09 tests\09.a "tests" ""
echo.
echo Generating answer for test #10
call scripts\gen-answer.bat tests\10 tests\10.a "tests" ""
echo.
echo Generating answer for test #11
call scripts\gen-answer.bat tests\11 tests\11.a "tests" ""
echo.
echo Generating answer for test #12
call scripts\gen-answer.bat tests\12 tests\12.a "tests" ""
echo.
echo Generating answer for test #13
call scripts\gen-answer.bat tests\13 tests\13.a "tests" ""
echo.
echo Generating answer for test #14
call scripts\gen-answer.bat tests\14 tests\14.a "tests" ""
echo.
echo Generating answer for test #15
call scripts\gen-answer.bat tests\15 tests\15.a "tests" ""
echo.
echo Generating answer for test #16
call scripts\gen-answer.bat tests\16 tests\16.a "tests" ""
echo.

