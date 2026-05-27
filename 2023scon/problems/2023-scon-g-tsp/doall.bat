rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen-complete.exe -n1=60 -n2=70 3" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\gen-complete.exe -n1=60 -n2=70 4" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2 -n2=2 -m1=1 -m2=1 -w1=0 -w2=0 5" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2 -n2=2 -m1=1 -m2=1 -w1=0 -w2=0 6" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2000 -n2=2000 -m1=5000 -m2=5000 -w1=0 -w2=0 7" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2000 -n2=2000 -m1=5000 -m2=5000 -w1=0 -w2=0 8" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2000 -n2=2000 -m1=5000 -m2=5000 -w1=0 -w2=0 9" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=2000 -n2=2000 -m1=5000 -m2=5000 -w1=0 -w2=0 10" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=1000 -n2=2000 -m1=0 -m2=5000 -w1=0 -w2=0 11" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=1000 -n2=2000 -m1=0 -m2=5000 -w1=0 -w2=0 12" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=1000 -n2=2000 -m1=0 -m2=5000 -w1=0 -w2=0 13" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=1000 -n2=2000 -m1=0 -m2=5000 -w1=0 -w2=0 14" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=1000 -n2=2000 -m1=0 -m2=5000 -w1=0 -w2=0 15" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=1000 -n2=2000 -m1=0 -m2=5000 -w1=0 -w2=0 16" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=1000 -n2=2000 -m1=0 -m2=5000 -w1=0 -w2=0 17" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=1000 -n2=2000 -m1=0 -m2=5000 -w1=0 -w2=0 18" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=1000 -n2=2000 -m1=0 -m2=5000 -w1=0 -w2=0 19" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\gen-rnd.exe -n1=1000 -n2=2000 -m1=0 -m2=5000 -w1=0 -w2=0 20" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\gen-rnd-tree.exe -n1=1900 -n2=2000 21" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\gen-rnd-tree.exe -n1=1900 -n2=2000 22" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\gen-rnd-tree.exe -n1=1900 -n2=2000 23" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\gen-rnd-tree.exe -n1=1900 -n2=2000 24" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\gen-rnd-tree.exe -n1=1900 -n2=2000 25" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\gen-kill-uf.exe -n=2000 -w=5000 -flag=0" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\gen-kill-uf.exe -n=2000 -w=5000 -flag=1" "tests\27" 27
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

