#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

int solve_for_target(const string& T, int startBit) {
    int n = (int)T.size();

    // D[i] = 현재 문자와 목표 alternating 문자열의 차이(0/1)
    vector<int> D(n);
    for (int i = 0; i < n; i++) {
        int target = (startBit + i) & 1;
        D[i] = (T[i] - '0') ^ target;
    }

    // dp[k] = 현재 위치까지 처리했고, 현재 열려 있는 구간 수가 k개일 때 최소 비용
    vector<int> dp(n + 1, INF), ndp(n + 1, INF);

    // 첫 번째 위치를 덮는 구간 수 k의 parity가 D[0]와 같아야 한다.
    // 처음에 k개를 여는 비용은 k
    for (int k = 0; k <= n; k++) {
        if ((k & 1) == D[0]) dp[k] = k;
    }

    // i번째 위치를 처리하고, i+1번째 위치로 넘어가는 경계에서
    // 열린 구간 수를 k -> nk 로 바꾸는 전이
    for (int i = 0; i < n - 1; i++) {
        fill(ndp.begin(), ndp.end(), INF);

        for (int k = 0; k <= n; k++) {
            if (dp[k] == INF) continue;

            // i번째 위치는 정확히 k개의 열린 구간에 덮여야 하므로 parity가 맞아야 함
            if ((k & 1) != D[i]) continue;

            for (int nk = 0; nk <= n; nk++) {
                // 다음 위치는 nk개의 열린 구간에 덮일 예정이므로 parity가 맞아야 함
                if ((nk & 1) != D[i + 1]) continue;

                // k -> nk 로 가면서 새로 시작해야 하는 구간 수
                int add = max(0, nk - k);
                ndp[nk] = min(ndp[nk], dp[k] + add);
            }
        }

        dp.swap(ndp);
    }

    int ret = INF;
    for (int k = 0; k <= n; k++) {
        if ((k & 1) == D[n - 1]) {
            ret = min(ret, dp[k]);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string T;
    cin >> N >> T;

    cout << min(solve_for_target(T, 0), solve_for_target(T, 1)) << '\n';
    return 0;
}