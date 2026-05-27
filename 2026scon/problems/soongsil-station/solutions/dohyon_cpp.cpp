#include <bits/stdc++.h>
using namespace std;

int L[3];

int solve(int idx, int t, int H) {
    if (idx == 3)
        return 1 <= H ? t : 600;
    return min(solve(idx + 1, t + L[idx], H), solve(idx + 1, t + L[idx] / 2, H - L[idx] / 2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 3; i++)
        cin >> L[i];
    int H;
    cin >> H;
    cout << solve(0, 0, H);
}