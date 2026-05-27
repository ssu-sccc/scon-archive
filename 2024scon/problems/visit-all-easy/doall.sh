#!/usr/bin/env bash
#   *** validation ***
scripts/run-validator-tests.sh
scripts/run-checker-tests.sh

#    *** tests ***
mkdir -p tests
echo "Generating test #2"
scripts/gen-input-via-stdout.sh "wine files/all-gen.exe '-N=99'" "tests/02" 2
echo "Generating test #3"
scripts/gen-input-via-stdout.sh "wine files/all-gen.exe '-N=100'" "tests/03" 3
echo "Generating test #4"
scripts/gen-input-via-stdout.sh "wine files/rand_gen.exe '-N=1000000000'" "tests/04" 4
echo "Generating test #5"
scripts/gen-input-via-stdout.sh "wine files/gen-small-all.exe '-mx=9'" "tests/05" 5
echo "Generating test #7"
scripts/gen-input-via-stdout.sh "wine files/gen-small-all.exe '-mx=31'" "tests/07" 7
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

