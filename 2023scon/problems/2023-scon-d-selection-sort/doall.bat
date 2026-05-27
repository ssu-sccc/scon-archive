rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=1 -n2=1 3" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2 -n2=2 4" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=3 -n2=3 5" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2000 -n2=5000 6" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2000 -n2=5000 7" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2000 -n2=5000 8" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2000 -n2=5000 9" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2000 -n2=5000 10" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=200000 -n2=500000 11" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=200000 -n2=500000 12" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=200000 -n2=500000 13" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=200000 -n2=500000 14" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=200000 -n2=500000 15" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=500000 -n2=500000 16" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=500000 -n2=500000 17" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=500000 -n2=500000 18" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=500000 -n2=500000 19" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=500000 -n2=500000 20" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\gen-shift.exe -n=500000 -inc=1 -sft=0 21" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\gen-shift.exe -n=500000 -inc=1 -sft=1 22" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\gen-shift.exe -n=500000 -inc=1 -sft=499999 23" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\gen-shift.exe -n=500000 -inc=1 -sft=250000 24" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\gen-shift.exe -n=500000 -inc=0 -sft=0 25" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\gen-shift.exe -n=500000 -inc=0 -sft=1 26" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\gen-shift.exe -n=500000 -inc=0 -sft=499999 27" "tests\27" 27
call scripts\gen-input-via-stdout.bat "files\gen-shift.exe -n=500000 -inc=0 -sft=250000 28" "tests\28" 28
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""
call scripts\gen-answer.bat tests\02 tests\02.a "tests" ""
call scripts\gen-answer.bat tests\03 tests\03.a "tests" ""
call scripts\gen-answer.bat tests\04 tests\04.a "tests" ""
call scripts\gen-answer.bat tests\05 tests\05.a "tests" ""
call scripts\gen-answer.bat tests\06 tests\06.a "tests" ""
call scripts\gen-answer.bat tests\07 tests\07.a "tests" ""
call scripts\gen-answer.bat tests\08 tests\08.a "tests" ""
call scripts\gen-answer.bat tests\09 tests\09.a "tests" ""
call scripts\gen-answer.bat tests\10 tests\10.a "tests" ""
call scripts\gen-answer.bat tests\11 tests\11.a "tests" ""
call scripts\gen-answer.bat tests\12 tests\12.a "tests" ""
call scripts\gen-answer.bat tests\13 tests\13.a "tests" ""
call scripts\gen-answer.bat tests\14 tests\14.a "tests" ""
call scripts\gen-answer.bat tests\15 tests\15.a "tests" ""
call scripts\gen-answer.bat tests\16 tests\16.a "tests" ""
call scripts\gen-answer.bat tests\17 tests\17.a "tests" ""
call scripts\gen-answer.bat tests\18 tests\18.a "tests" ""
call scripts\gen-answer.bat tests\19 tests\19.a "tests" ""
call scripts\gen-answer.bat tests\20 tests\20.a "tests" ""
call scripts\gen-answer.bat tests\21 tests\21.a "tests" ""
call scripts\gen-answer.bat tests\22 tests\22.a "tests" ""
call scripts\gen-answer.bat tests\23 tests\23.a "tests" ""
call scripts\gen-answer.bat tests\24 tests\24.a "tests" ""
call scripts\gen-answer.bat tests\25 tests\25.a "tests" ""
call scripts\gen-answer.bat tests\26 tests\26.a "tests" ""
call scripts\gen-answer.bat tests\27 tests\27.a "tests" ""
call scripts\gen-answer.bat tests\28 tests\28.a "tests" ""

