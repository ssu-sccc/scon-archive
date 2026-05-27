#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

using ll = long long;
using pi = pair<ll, ll>;

#define x first
#define y second

bool incr(pi a, pi b) {
    return a.x < b.x && a.y < b.y;
}

int n, dp[2][3030][3030], ldp[3030];
pi arr[3030];
double ang[3030];
vector<int> li, ri;

void fillDP(int j) {
    li.clear();
    ri.clear();

    for (int i = 0; i < j; i++) {
        if (incr(arr[i], arr[j])) {
            li.push_back(i);
            ang[i] = atan((double)(arr[i].y - arr[j].y) / (double)(arr[i].x - arr[j].x));
        }
    }

    for (int i = j + 1; i <= n; i++) {
        if (incr(arr[j], arr[i])) {
            ri.push_back(i);
            ang[i] = atan((double)(arr[i].y - arr[j].y) / (double)(arr[i].x - arr[j].x));
        }
    }

    auto cmp = [&](int a, int b) -> bool {
        return ang[a] < ang[b];
    };

    sort(all(li), cmp);
    sort(all(ri), cmp);

    int lsz = (int)li.size();

    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < lsz; i++) ldp[i] = dp[t ^ 1][li[i]][j];

        int p = 0, mx = 0;
        for (int r : ri) {
            while (p < lsz && (t ? cmp(li[p], r) : cmp(r, li[p]))) {
                mx = max(mx, ldp[p]);
                p++;
            }
            if (mx >= 1) dp[t][j][r] = max(dp[t][j][r], mx + 1);
        }

        reverse(all(li));
        reverse(all(ri));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr[0] = {0, 0};
    for (int i = 1; i <= n; i++) cin >> arr[i].x >> arr[i].y;

    sort(arr, arr + n + 1);

    for (int i = 1; i <= n; i++) {
        dp[0][0][i] = 1;
        dp[1][0][i] = 1;
    }

    for (int i = 1; i <= n; i++) fillDP(i);

    int ans = 1;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, *max_element(dp[0][i], dp[0][i] + n + 1));
        ans = max(ans, *max_element(dp[1][i], dp[1][i] + n + 1));
    }

    cout << ans << '\n';
    return 0;
}