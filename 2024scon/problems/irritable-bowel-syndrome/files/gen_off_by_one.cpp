#include "testlib.h"
#include <iostream>

#define N_MAX 100'000
#define M_MAX 1'000'000'000

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int N = __testlib_opts.count("N") ? opt<int>("N") : rnd.next(1, N_MAX);
    int M = __testlib_opts.count("M") ? opt<int>("M") : rnd.next(1, min(M_MAX, N * 10'000 - 1'000));

    int acc = 0;
    vector<int> v;

    while(v.size() < N) {
        v.push_back(min(10'000, M - acc));
        acc += min(10'000, M - acc);
        if(acc == M) break;
    }

    int prev = 0;
    while(v.size() < N) {
        if(prev == 0) {
            prev = rnd.next(-10'000, 10'000);
            acc += prev;
            v.push_back(prev);
        } else {
            acc -= prev;
            v.push_back(-prev);
            prev = 0;
        }
    }

    cout << N << ' ' << M << '\n';
    for(int i=0; i<N; i++) cout << v[i] << " \n"[i == N-1];

    return 0;
}
