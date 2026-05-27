@echo off
rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
echo Generating test #3
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""1"" ""1""" "tests\03" 3
echo Generating test #4
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""1"" ""20""" "tests\04" 4
echo Generating test #5
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""2"" ""3""" "tests\05" 5
echo Generating test #6
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""3"" ""19""" "tests\06" 6
echo Generating test #7
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""10"" ""9""" "tests\07" 7
echo Generating test #8
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""50"" ""5""" "tests\08" 8
echo Generating test #9
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""328"" ""20""" "tests\09" 9
echo Generating test #10
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""1000"" ""11""" "tests\10" 10
echo Generating test #11
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""8160"" ""16""" "tests\11" 11
echo Generating test #12
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""10000"" ""17""" "tests\12" 12
echo Generating test #13
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""12345"" ""6""" "tests\13" 13
echo Generating test #14
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""37914"" ""7""" "tests\14" 14
echo Generating test #15
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""50000"" ""1""" "tests\15" 15
echo Generating test #16
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""50000"" ""18""" "tests\16" 16
echo Generating test #17
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""50000"" ""19""" "tests\17" 17
echo Generating test #18
call scripts\gen-input-via-stdout.bat "files\gen_xorpal.exe ""50000"" ""20""" "tests\18" 18
echo Generating test #19
call scripts\gen-input-via-stdout.bat "files\gen_xorpal_all.exe ""5""" "tests\19" 19
echo Generating test #20
call scripts\gen-input-via-stdout.bat "files\gen_xorpal_all.exe ""10""" "tests\20" 20
echo Generating test #21
call scripts\gen-input-via-stdout.bat "files\gen_xorpal_all.exe ""14""" "tests\21" 21
echo Generating test #22
call scripts\gen-input-via-stdout.bat "files\gen_xorpal_all.exe ""15""" "tests\22" 22
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
echo Generating answer for test #17
call scripts\gen-answer.bat tests\17 tests\17.a "tests" ""
echo.
echo Generating answer for test #18
call scripts\gen-answer.bat tests\18 tests\18.a "tests" ""
echo.
echo Generating answer for test #19
call scripts\gen-answer.bat tests\19 tests\19.a "tests" ""
echo.
echo Generating answer for test #20
call scripts\gen-answer.bat tests\20 tests\20.a "tests" ""
echo.
echo Generating answer for test #21
call scripts\gen-answer.bat tests\21 tests\21.a "tests" ""
echo.
echo Generating answer for test #22
call scripts\gen-answer.bat tests\22 tests\22.a "tests" ""
echo.

