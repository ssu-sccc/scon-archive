#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
using namespace std;

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(101);
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a]++;
        v[b]++;
        v[c]++;
    }

    int ans = 0;
    for (int i = 1; i < 101; i++) {
        for (int j = i + 1; j < 101; j++) {
            for (int k = j + 1; k < 101; k++) {
                v[i]++;
                v[j]++;
                v[k]++;

                set<int> cur = {i, j, k};
                int prize_cut = 101;
                while (prize_cut--) {
                    if (v[prize_cut] == 1) {
                        if (cur.count(prize_cut)) {
                            ans++;
                        }
                        break;
                    }
                }

                v[i]--;
                v[j]--;
                v[k]--;
            }
        }
    }
    cout << ans << endl;
}
