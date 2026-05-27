#include "testlib.h"
#include <iostream>

#define N_MAX 100'000
#define M_MAX 1'000'000'000
#define A_MIN -10'000
#define A_MAX 10'000

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, N_MAX, "N"); inf.readSpace();
    int M = inf.readInt(1, M_MAX, "M"); inf.readEoln();

    for(int i=0; i<N; i++) {
        inf.readInt(A_MIN, A_MAX, "A[" + to_string(i) + "]");
        if(i < N-1) inf.readSpace();
    }

    inf.readEoln();
    inf.readEof();

    return 0;
}
