#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
constexpr int MIN_N = 1;
constexpr int MAX_N = 8'192;


int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int N = inf.readInt(1, MAX_N, "N");

    vector<int> A = ouf.readInts(N, 1, 6 * N, "A");
    
    ouf.seekEof();
    

    vector<long long> pref(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        pref[i] = pref[i - 1] + A[i-1];
    }

    vector<long long> sums;
    sums.reserve(1LL * N * (N + 1) / 2);

    for (int l = 1; l <= N; l++) {
        for (int r = l; r <= N; r++) {
            sums.push_back(pref[r] - pref[l - 1]);
        }
    }

    sort(sums.begin(), sums.end());
    for (int i = 1; i < (int)sums.size(); i++) {
        if (sums[i] == sums[i - 1]) {
            quitf(_wa, "there exist at least two subarrays with equal sum %lld", sums[i]);
        }
    }

    quitf(_ok, "valid sequence");
}