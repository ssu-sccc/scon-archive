rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe 1" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe 2" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe 3" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe 4" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe 5" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe 6" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe 7" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe 8" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe 9" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe 10" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe -n=15 -k=15 1" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe -n=15 -k=15 2" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe -n=15 -k=15 3" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe -n=15 -k=15 4" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe -n=15 -k=15 5" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe -n=15 -k=15 6" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe -n=15 -k=15 7" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe -n=15 -k=15 8" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe -n=15 -k=15 9" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe -n=15 -k=15 10" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=15" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\gen_rnd.exe -n=15 -k=1 -x=15" "tests\32" 32
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=1" "tests\37" 37
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=2" "tests\38" 38
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=3" "tests\39" 39
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=4" "tests\40" 40
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=5" "tests\41" 41
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=6" "tests\42" 42
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=7" "tests\43" 43
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=8" "tests\44" 44
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=9" "tests\45" 45
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=10" "tests\46" 46
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=11" "tests\47" 47
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=12" "tests\48" 48
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=13" "tests\49" 49
call scripts\gen-input-via-stdout.bat "files\gen_rnd_dense.exe -n=15 -k=14" "tests\50" 50
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
call scripts\gen-answer.bat tests\29 tests\29.a "tests" ""
call scripts\gen-answer.bat tests\30 tests\30.a "tests" ""
call scripts\gen-answer.bat tests\31 tests\31.a "tests" ""
call scripts\gen-answer.bat tests\32 tests\32.a "tests" ""
call scripts\gen-answer.bat tests\33 tests\33.a "tests" ""
call scripts\gen-answer.bat tests\34 tests\34.a "tests" ""
call scripts\gen-answer.bat tests\35 tests\35.a "tests" ""
call scripts\gen-answer.bat tests\36 tests\36.a "tests" ""
call scripts\gen-answer.bat tests\37 tests\37.a "tests" ""
call scripts\gen-answer.bat tests\38 tests\38.a "tests" ""
call scripts\gen-answer.bat tests\39 tests\39.a "tests" ""
call scripts\gen-answer.bat tests\40 tests\40.a "tests" ""
call scripts\gen-answer.bat tests\41 tests\41.a "tests" ""
call scripts\gen-answer.bat tests\42 tests\42.a "tests" ""
call scripts\gen-answer.bat tests\43 tests\43.a "tests" ""
call scripts\gen-answer.bat tests\44 tests\44.a "tests" ""
call scripts\gen-answer.bat tests\45 tests\45.a "tests" ""
call scripts\gen-answer.bat tests\46 tests\46.a "tests" ""
call scripts\gen-answer.bat tests\47 tests\47.a "tests" ""
call scripts\gen-answer.bat tests\48 tests\48.a "tests" ""
call scripts\gen-answer.bat tests\49 tests\49.a "tests" ""
call scripts\gen-answer.bat tests\50 tests\50.a "tests" ""
call scripts\gen-answer.bat tests\51 tests\51.a "tests" ""
call scripts\gen-answer.bat tests\52 tests\52.a "tests" ""
call scripts\gen-answer.bat tests\53 tests\53.a "tests" ""
call scripts\gen-answer.bat tests\54 tests\54.a "tests" ""
call scripts\gen-answer.bat tests\55 tests\55.a "tests" ""
call scripts\gen-answer.bat tests\56 tests\56.a "tests" ""
call scripts\gen-answer.bat tests\57 tests\57.a "tests" ""
call scripts\gen-answer.bat tests\58 tests\58.a "tests" ""
call scripts\gen-answer.bat tests\59 tests\59.a "tests" ""
call scripts\gen-answer.bat tests\60 tests\60.a "tests" ""
call scripts\gen-answer.bat tests\61 tests\61.a "tests" ""
call scripts\gen-answer.bat tests\62 tests\62.a "tests" ""
call scripts\gen-answer.bat tests\63 tests\63.a "tests" ""
call scripts\gen-answer.bat tests\64 tests\64.a "tests" ""
call scripts\gen-answer.bat tests\65 tests\65.a "tests" ""
call scripts\gen-answer.bat tests\66 tests\66.a "tests" ""
call scripts\gen-answer.bat tests\67 tests\67.a "tests" ""
call scripts\gen-answer.bat tests\68 tests\68.a "tests" ""
call scripts\gen-answer.bat tests\69 tests\69.a "tests" ""
call scripts\gen-answer.bat tests\70 tests\70.a "tests" ""
call scripts\gen-answer.bat tests\71 tests\71.a "tests" ""

