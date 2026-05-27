#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXC = 1000000000LL;

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    int seed = argc > 2 ? atoi(argv[2]) : 42;
    mt19937 rng(seed);

    // --- seed 기반 variation ---
    int pct      = 50 + (int)(rng() % 26);              // 50~75% 가 convex chain
    double expo  = 1.5 + (rng() % 1001) / 1000.0;       // 1.5 ~ 2.5 (convex 유지)
    ll xScale    = 300000000LL + (ll)(rng() % 150000000LL);
    ll tailScale = 200000000LL + (ll)(rng() % 150000000LL);
    ll x0        = 1 + (ll)(rng() % 10000);
    ll y0        = 1 + (ll)(rng() % 10000);

    int L = max(1, n * pct / 100);
    int M = n - L;

    vector<pair<ll,ll>> pts;

    // Convex chain (y ~ x^expo): 기울기 단조 증가 → 체인 조건 ok
    for (int i = 0; i < L; i++) {
        double t = (double)(i + 1) / L;
        ll x = x0 + (ll)(t * xScale);
        ll y = y0 + (ll)(pow(t, expo) * xScale);
        if (!pts.empty()) {
            x = max(x, pts.back().first + 1);
            y = max(y, pts.back().second + 1);
        }
        x = min(x, MAXC);
        y = min(y, MAXC);
        pts.push_back({x, y});
    }

    // Flat tail: 큰 x 점프 + y += 1, step에 약간 jitter
    ll lx = pts.back().first, ly = pts.back().second;
    ll baseStep = max(1LL, tailScale / (M + 1));
    for (int i = 0; i < M; i++) {
        ll jitter = (ll)(rng() % max(1LL, baseStep / 20)); // step의 ±5% 내
        lx += baseStep + jitter;
        ly += 1;
        if (lx > MAXC || ly > MAXC) break;
        pts.push_back({lx, ly});
    }

    n = (int)pts.size();
    cout << n << "\n";
    for (auto& [x, y] : pts) cout << x << " " << y << "\n";
}