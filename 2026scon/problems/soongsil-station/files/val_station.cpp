#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int A = inf.readInt(2, 200, "A");
    ensuref(A % 2 == 0, "A must be an even number");
    inf.readSpace();
    int B = inf.readInt(2, 200, "B");
    ensuref(B % 2 == 0, "B must be an even number");
    inf.readSpace();
    int C = inf.readInt(2, 200, "C");
    ensuref(C % 2 == 0, "C must be an even number");
    inf.readEoln();
    int H = inf.readInt(1, 200, "H");
    inf.readEoln();
    inf.readEof();
}
