#include "testlib.h"
#include <iostream>

#define N_MAX 500'000
#define A_MAX 1'000'000

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = __testlib_opts.count("N") ? opt<int>("N") : rnd.next(1, N_MAX);

    cout << N << '\n';

    for(int i=0; i<N; i++) {
        int a = rnd.next(1, A_MAX);
        cout << a << " \n"[i == N-1];
    }

    return 0;
}