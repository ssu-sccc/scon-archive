#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir -p tests
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "wine files/gen_prize_01.exe 1" "tests/04" 4
echo "Generating test #5"
scripts/gen-input-via-stdout.sh "wine files/gen_prize_01.exe 5" "tests/05" 5
echo "Generating test #6"
scripts/gen-input-via-stdout.sh "wine files/gen_prize_01.exe 10" "tests/06" 6
echo "Generating test #7"
scripts/gen-input-via-stdout.sh "wine files/gen_prize_01.exe 50" "tests/07" 7
echo "Generating test #8"
scripts/gen-input-via-stdout.sh "wine files/gen_prize_01.exe 100" "tests/08" 8
echo ""
echo "Generating answer for test #1"
scripts/gen-answer.sh tests/01 tests/01.a "tests" ""
echo ""
echo "Generating answer for test #2"
scripts/gen-answer.sh tests/02 tests/02.a "tests" ""
echo ""
echo "Generating answer for test #3"
scripts/gen-answer.sh tests/03 tests/03.a "tests" ""
echo ""
echo "Generating answer for test #4"
scripts/gen-answer.sh tests/04 tests/04.a "tests" ""
echo ""
echo "Generating answer for test #5"
scripts/gen-answer.sh tests/05 tests/05.a "tests" ""
echo ""
echo "Generating answer for test #6"
scripts/gen-answer.sh tests/06 tests/06.a "tests" ""
echo ""
echo "Generating answer for test #7"
scripts/gen-answer.sh tests/07 tests/07.a "tests" ""
echo ""
echo "Generating answer for test #8"
scripts/gen-answer.sh tests/08 tests/08.a "tests" ""
echo ""
echo "Generating answer for test #9"
scripts/gen-answer.sh tests/09 tests/09.a "tests" ""
echo ""
echo "Generating answer for test #10"
scripts/gen-answer.sh tests/10 tests/10.a "tests" ""
echo ""
echo "Generating answer for test #11"
scripts/gen-answer.sh tests/11 tests/11.a "tests" ""
echo ""
echo "Generating answer for test #12"
scripts/gen-answer.sh tests/12 tests/12.a "tests" ""
echo ""
echo "Generating answer for test #13"
scripts/gen-answer.sh tests/13 tests/13.a "tests" ""
echo ""

