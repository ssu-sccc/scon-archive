@echo off
rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
echo Generating test #7
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""1""" "tests\07" 7
echo Generating test #8
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""2""" "tests\08" 8
echo Generating test #9
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""3""" "tests\09" 9
echo Generating test #10
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""4""" "tests\10" 10
echo Generating test #11
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""5""" "tests\11" 11
echo Generating test #12
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""1""" "tests\12" 12
echo Generating test #13
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""2""" "tests\13" 13
echo Generating test #14
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""3""" "tests\14" 14
echo Generating test #15
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""4""" "tests\15" 15
echo Generating test #16
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""5""" "tests\16" 16
echo Generating test #17
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""6""" "tests\17" 17
echo Generating test #18
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""7""" "tests\18" 18
echo Generating test #19
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""8""" "tests\19" 19
echo Generating test #20
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""9""" "tests\20" 20
echo Generating test #21
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""10""" "tests\21" 21
echo Generating test #22
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""11""" "tests\22" 22
echo Generating test #23
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""12""" "tests\23" 23
echo Generating test #24
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""13""" "tests\24" 24
echo Generating test #25
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""14""" "tests\25" 25
echo Generating test #26
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""15""" "tests\26" 26
echo Generating test #27
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""16""" "tests\27" 27
echo Generating test #28
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""17""" "tests\28" 28
echo Generating test #29
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""18""" "tests\29" 29
echo Generating test #30
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""19""" "tests\30" 30
echo Generating test #31
call scripts\gen-input-via-stdout.bat "files\rand_gen.exe ""200000"" ""20""" "tests\31" 31
echo Generating test #32
call scripts\gen-input-via-stdout.bat "files\sp_gen1.exe ""1""" "tests\32" 32
echo Generating test #33
call scripts\gen-input-via-stdout.bat "files\sp_gen1.exe ""2""" "tests\33" 33
echo Generating test #34
call scripts\gen-input-via-stdout.bat "files\sp_gen1.exe ""3""" "tests\34" 34
echo Generating test #35
call scripts\gen-input-via-stdout.bat "files\sp_gen2.exe" "tests\35" 35
echo Generating test #36
call scripts\gen-input-via-stdout.bat "files\sp_gen3.exe" "tests\36" 36
echo Generating test #37
call scripts\gen-input-via-stdout.bat "files\same_gen.exe" "tests\37" 37
echo Generating test #38
call scripts\gen-input-via-stdout.bat "files\max_gen.exe ""200000"" ""1""" "tests\38" 38
echo Generating test #39
call scripts\gen-input-via-stdout.bat "files\max_gen.exe ""200000"" ""2""" "tests\39" 39
echo Generating test #40
call scripts\gen-input-via-stdout.bat "files\max_gen.exe ""200000"" ""3""" "tests\40" 40
echo Generating test #41
call scripts\gen-input-via-stdout.bat "files\max_gen.exe ""200000"" ""4""" "tests\41" 41
echo Generating test #42
call scripts\gen-input-via-stdout.bat "files\max_gen.exe ""200000"" ""5""" "tests\42" 42
echo Generating test #43
call scripts\gen-input-via-stdout.bat "files\max_gen.exe ""58""" "tests\43" 43
echo Generating test #44
call scripts\gen-input-via-stdout.bat "files\max_gen.exe ""59""" "tests\44" 44
echo Generating test #45
call scripts\gen-input-via-stdout.bat "files\max_gen.exe ""60""" "tests\45" 45
echo Generating test #46
call scripts\gen-input-via-stdout.bat "files\max_gen.exe ""61""" "tests\46" 46
echo Generating test #47
call scripts\gen-input-via-stdout.bat "files\max_gen.exe ""62""" "tests\47" 47
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
echo Generating answer for test #23
call scripts\gen-answer.bat tests\23 tests\23.a "tests" ""
echo.
echo Generating answer for test #24
call scripts\gen-answer.bat tests\24 tests\24.a "tests" ""
echo.
echo Generating answer for test #25
call scripts\gen-answer.bat tests\25 tests\25.a "tests" ""
echo.
echo Generating answer for test #26
call scripts\gen-answer.bat tests\26 tests\26.a "tests" ""
echo.
echo Generating answer for test #27
call scripts\gen-answer.bat tests\27 tests\27.a "tests" ""
echo.
echo Generating answer for test #28
call scripts\gen-answer.bat tests\28 tests\28.a "tests" ""
echo.
echo Generating answer for test #29
call scripts\gen-answer.bat tests\29 tests\29.a "tests" ""
echo.
echo Generating answer for test #30
call scripts\gen-answer.bat tests\30 tests\30.a "tests" ""
echo.
echo Generating answer for test #31
call scripts\gen-answer.bat tests\31 tests\31.a "tests" ""
echo.
echo Generating answer for test #32
call scripts\gen-answer.bat tests\32 tests\32.a "tests" ""
echo.
echo Generating answer for test #33
call scripts\gen-answer.bat tests\33 tests\33.a "tests" ""
echo.
echo Generating answer for test #34
call scripts\gen-answer.bat tests\34 tests\34.a "tests" ""
echo.
echo Generating answer for test #35
call scripts\gen-answer.bat tests\35 tests\35.a "tests" ""
echo.
echo Generating answer for test #36
call scripts\gen-answer.bat tests\36 tests\36.a "tests" ""
echo.
echo Generating answer for test #37
call scripts\gen-answer.bat tests\37 tests\37.a "tests" ""
echo.
echo Generating answer for test #38
call scripts\gen-answer.bat tests\38 tests\38.a "tests" ""
echo.
echo Generating answer for test #39
call scripts\gen-answer.bat tests\39 tests\39.a "tests" ""
echo.
echo Generating answer for test #40
call scripts\gen-answer.bat tests\40 tests\40.a "tests" ""
echo.
echo Generating answer for test #41
call scripts\gen-answer.bat tests\41 tests\41.a "tests" ""
echo.
echo Generating answer for test #42
call scripts\gen-answer.bat tests\42 tests\42.a "tests" ""
echo.
echo Generating answer for test #43
call scripts\gen-answer.bat tests\43 tests\43.a "tests" ""
echo.
echo Generating answer for test #44
call scripts\gen-answer.bat tests\44 tests\44.a "tests" ""
echo.
echo Generating answer for test #45
call scripts\gen-answer.bat tests\45 tests\45.a "tests" ""
echo.
echo Generating answer for test #46
call scripts\gen-answer.bat tests\46 tests\46.a "tests" ""
echo.
echo Generating answer for test #47
call scripts\gen-answer.bat tests\47 tests\47.a "tests" ""
echo.

