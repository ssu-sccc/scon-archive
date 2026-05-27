#include "testlib.h"
#include <iostream>
#include <algorithm>

#define N_MAX 100'000
#define M_MAX 1'000'000'000

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = __testlib_opts.count("N") ? opt<int>("N") : rnd.next(1, N_MAX);

    int acc = 0, greatest = 0;
    vector<int> v;

    while(true) {
        acc = 0;
        greatest = 0;
        v = vector<int>();

        for(int i=0; i<N; i++) {
            int a = rnd.next(-10'000, 10'000);
            v.push_back(a);

            acc = max(0, acc + a);
            greatest = max(greatest, acc);
        }

        if(greatest < M_MAX) break;
    }

    int M = __testlib_opts.count("M") ? opt<int>("M") : rnd.next(greatest+1, M_MAX);

    cout << N << ' ' << M << '\n';
    for(int i=0; i<N; i++) cout << v[i] << " \n"[i == N-1];

    return 0;
}
