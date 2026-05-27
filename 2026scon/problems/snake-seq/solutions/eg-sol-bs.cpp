#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 3005;

struct Point {
    long long x, y;
};

static Point p[MAXN];
static uint16_t upv[MAXN][MAXN];
static uint16_t dnv[MAXN][MAXN];
static uint16_t pref[MAXN], suf[MAXN];

inline bool slope_less_to_i(int a, int b, int i) {
    long long lhs = (p[i].y - p[a].y) * (p[i].x - p[b].x);
    long long rhs = (p[i].y - p[b].y) * (p[i].x - p[a].x);
    return lhs < rhs;
}

inline int cmp_pred_target(int k, int i, int j) {
    long long lhs = (p[i].y - p[k].y) * (p[j].x - p[i].x);
    long long rhs = (p[j].y - p[i].y) * (p[i].x - p[k].x);
    if (lhs < rhs) return -1;
    if (lhs > rhs) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Point> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i].x >> a[i].y;

    sort(a.begin(), a.end(), [](const Point& A, const Point& B) {
        if (A.x != B.x) return A.x < B.x;
        return A.y < B.y;
    });

    p[0] = {0, 0};
    for (int i = 1; i <= N; ++i) p[i] = a[i - 1];

    for (int i = 1; i <= N; ++i) upv[0][i] = dnv[0][i] = 1;

    int ans = 1;
    vector<int> pred;
    pred.reserve(N + 1);

    for (int i = 1; i <= N; ++i) {
        pred.clear();
        pred.push_back(0);

        for (int k = 1; k < i; ++k) {
            if (p[k].x < p[i].x && p[k].y < p[i].y && (upv[k][i] || dnv[k][i])) {
                pred.push_back(k);
            }
        }

        sort(pred.begin(), pred.end(), [i](int a, int b) {
            return slope_less_to_i(a, b, i);
        });

        int m = (int)pred.size();

        for (int t = 0; t < m; ++t) {
            uint16_t v = dnv[pred[t]][i];
            pref[t] = t ? max(pref[t - 1], v) : v;
        }

        for (int t = m - 1; t >= 0; --t) {
            uint16_t v = upv[pred[t]][i];
            suf[t] = (t + 1 < m ? max(suf[t + 1], v) : v);
        }

        for (int j = i + 1; j <= N; ++j) {
            if (!(p[i].x < p[j].x && p[i].y < p[j].y)) continue;

            int l = 0, r = m;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (cmp_pred_target(pred[mid], i, j) < 0) l = mid + 1;
                else r = mid;
            }
            if (l > 0) {
                upv[i][j] = pref[l - 1] + 1;
                ans = max(ans, (int)upv[i][j]);
            }

            l = 0, r = m;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (cmp_pred_target(pred[mid], i, j) <= 0) l = mid + 1;
                else r = mid;
            }
            if (l < m) {
                dnv[i][j] = suf[l] + 1;
                ans = max(ans, (int)dnv[i][j]);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}