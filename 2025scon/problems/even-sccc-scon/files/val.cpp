#include "testlib.h"
#include <iostream>

#define N_MAX 1'000'000

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, N_MAX, "N");

    inf.readEoln();
    inf.readEof();

    return 0;
}