#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int seed = atoi(argv[2]);
    mt19937 rng(seed);

    // x, y 둘 다 순증가 보장 → 모든 쌍이 incr → 풀 N³
    // 기울기는 랜덤하게 흔들어서 convex/line 감지 불가
    vector<pair<long long, long long>> pts(n);
    long long cx = 0, cy = 0;
    for (int i = 0; i < n; i++) {
        cx += rng() % 300000 + 1;   // x 증가량 [1, 300000]
        cy += rng() % 300000 + 1;   // y 증가량 [1, 300000]
        pts[i] = {cx, cy};
    }

    // 좌표가 10^9 넘지 않게 스케일링
    long long mx = pts.back().first;
    long long my = pts.back().second;
    for (int i = 0; i < n; i++) {
        pts[i].first = max(1LL, pts[i].first * 999999999 / mx);
        pts[i].second = max(1LL, pts[i].second * 999999999 / my);
    }
    // 스케일링 후 순증가 보장
    for (int i = 1; i < n; i++) {
        pts[i].first = max(pts[i].first, pts[i-1].first + 1);
        pts[i].second = max(pts[i].second, pts[i-1].second + 1);
    }

    cout << n << "\n";
    for (int i = 0; i < n; i++)
        cout << pts[i].first << " " << pts[i].second << "\n";
}