#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    int n; cin >> n;
    vector<array<ll, 3>>A(n);
    for(auto &[a, b, c] : A)cin >> a >> b >> c;
    vector cnt(101, 0), T(101, 0), S(101, 0);
    for(auto [a, b, c] : A)cnt[a]++, cnt[b]++, cnt[c]++;
    int ans = 0;
    for(int s = 1; s <= 100; s++)for(int e = s + 1; e <= 100; e++)for(int x = e + 1; x <= 100; x++){
        cnt[s]++; cnt[e]++; cnt[x]++;
        int fir = -1;
        for(int y = 100; y >= 1; y--)if(cnt[y] == 1){
            fir = y;
            break;
        }
        if(fir == s || fir == e || fir == x)ans++;
        cnt[s]--; cnt[e]--; cnt[x]--;
    }
    cout << ans;
}
