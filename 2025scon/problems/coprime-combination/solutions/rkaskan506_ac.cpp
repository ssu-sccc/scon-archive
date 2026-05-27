#include <bits/stdc++.h>

using ll = long long;
using namespace std;
#define MOD 1000000007

int T = 1, SZ = 1e8;

int INP[5050];

void solve() {
    vector<int> cnt1(5050, 0), cnt2(5050, 0);
    int n1, r1, n2, r2; cin >> n1 >> r1 >> n2 >> r2;

    if(n1 == 1 || r1 == n1 || r1 == 0 || n2 == 1 || r2 == n2 || r2 == 0) {
        cout << "1\n";
        return;
    }

    r1 = min(r1, n1-r1);
    r2 = min(r2, n2-r2);

    for(int i = n1, j = 1; j <= r1; i--, j++) {
        cnt1[i]++; cnt1[j]--;
    }

    for(int i = n2, j = 1; j <= r2; i--, j++) {
        cnt2[i]++; cnt2[j]--;
    }

    int res = 0;

    for(int i = 5000; i >= 2; i--) {
        if(!INP[i]) {
            res |= (cnt1[i]&&cnt2[i]);
        }
        else {
            int j = i/INP[i];

            cnt1[j] += cnt1[i];
            cnt1[INP[i]] += cnt1[i];
            cnt2[j] += cnt2[i];
            cnt2[INP[i]] += cnt2[i];
        }
    }

    res = !res;
    cout << res << "\n";
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    for(int i = 2; i*i <= 5000; i++) {
        if(!INP[i]) {
            for(int j = i+i; j <= 5000; j += i) {
                INP[j] = i;
            }
        }
    }

    cin >> T;
    while(T--) solve();
}    
