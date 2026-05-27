#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, c, d, a[202], dp[202][25252];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> c >> d;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++) {
        for(int s=1;s<=c;s++) {
            multiset<int> S;
            for(int j=s;j-d<=m;j+=c) {
                if(j <= m) S.insert(dp[i-1][j]);
                if(j-d >= 1) dp[i][j-d] = *S.rbegin();
                if(j-d-d >= 1) S.erase(S.find(dp[i-1][j-d-d]));
            }
        }
        for(int j=1;j<=m;j++) dp[i][j] += m-abs(a[i]-j);
    }

    cout << *max_element(dp[n]+1, dp[n]+1+m);
}