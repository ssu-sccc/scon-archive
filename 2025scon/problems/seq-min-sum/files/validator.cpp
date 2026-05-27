#include "testlib.h"
#include <iostream>

#define N_MAX 500'000
#define A_MAX 1'000'000

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, N_MAX, "N"); inf.readEoln();

    for(int i=1; i<=N; i++) {
        inf.readInt(1, A_MAX, "A[" + to_string(i) + "]");
        if(i < N) inf.readSpace();
    }

    inf.readEoln();
    inf.readEof();

    return 0;
}