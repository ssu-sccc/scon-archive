#include "testlib.h"
#include <iostream>

#define N_MAX 100'000
#define M_MAX 1'000'000'000

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = __testlib_opts.count("N") ? opt<int>("N") : rnd.next(1, N_MAX);
    int M = __testlib_opts.count("M") ? opt<int>("M") : rnd.next(1, M_MAX);

    cout << N << ' ' << M << '\n';

    for(int i=0; i<N; i++) {
        int a = rnd.next(-10'000, 10'000);
        cout << a << " \n"[i == N-1];
    }

    return 0;
}
