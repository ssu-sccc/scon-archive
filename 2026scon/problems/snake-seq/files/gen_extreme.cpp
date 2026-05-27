#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const long long MAXC = 1000000000LL;
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int nExtreme = argc > 2 ? atoi(argv[2]) : min(n, 8);
    set<pair<long long, long long>> pts;
    vector<pair<long long, long long>> res;
    vector<pair<long long, long long>> candidates;
    for (int k = 0; k < nExtreme; k++) {
        candidates.push_back({1 + k, 1 + k});
        candidates.push_back({1 + k, 1 + k + 1});
        candidates.push_back({1 + k + 1, 1 + k});
        candidates.push_back({MAXC - k, MAXC - k});
        candidates.push_back({MAXC - k, MAXC - k - 1});
        candidates.push_back({MAXC - k - 1, MAXC - k});
        candidates.push_back({1 + k, MAXC - k});
        candidates.push_back({MAXC - k, 1 + k});
    }
    shuffle(candidates.begin(), candidates.end());
    for (auto &p : candidates) {
        if ((int)res.size() >= nExtreme) break;
        if (pts.insert(p).second)
            res.push_back(p);
    }
    while ((int)res.size() < n) {
        long long x = rnd.next(1LL, MAXC);
        long long y = rnd.next(1LL, MAXC);
        if (pts.insert({x, y}).second)
            res.push_back({x, y});
    }
    shuffle(res.begin(), res.end());
    printf("%d\n", n);
    for (auto &[x, y] : res)
        printf("%lld %lld\n", x, y);
}