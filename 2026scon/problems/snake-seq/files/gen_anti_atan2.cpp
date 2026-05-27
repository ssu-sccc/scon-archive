#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
// K collinear-ish points (slopes ~1, no zigzag) + noise
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int K = argc > 2 ? atoi(argv[2]) : 200;
    ll M = argc > 3 ? atoll(argv[3]) : 0;
    if (M == 0) M = 900000000LL / K;
    set<pi> pts;
    vector<pi> res;
    ll cx = 1, cy = 1;
    for (int k = 0; k < K; k++) {
        ensuref(cx >= 1 && cx <= 1000000000LL, "x out of range");
        ensuref(cy >= 1 && cy <= 1000000000LL, "y out of range");
        if (pts.insert({cx, cy}).second)
            res.push_back({cx, cy});
        cx += M + k;
        cy += M + k + 1;
    }
    while ((int)res.size() < n) {
        ll x = rnd.next(1LL, 1000000000LL);
        ll y = rnd.next(1LL, 1000LL);
        if (pts.insert({x, y}).second)
            res.push_back({x, y});
    }
    shuffle(res.begin(), res.end());
    printf("%d\n", (int)res.size());
    for (auto &[x, y] : res)
        printf("%lld %lld\n", x, y);
}