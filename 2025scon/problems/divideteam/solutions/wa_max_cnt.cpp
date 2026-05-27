#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll>A(n+1), B(n+1), S(n+1);
    for(int s=1; s<=n; s++)cin >> A[s];
    for(int s=1; s<=n; s++)cin >> B[s];
    for(int s=1; s<=n; s++)S[s] = S[s-1] + B[s] * (A[s] ? 1 : -1);
    vector<ll>P;
    for(int s=1; s<n; s++)P.push_back(S[n] - S[s]);
    ll cnt = 1, ans = S[n];
    sort(all(P));
    for(int s=n-2; s>=0; s--)if(P[s] >= 0){
        cnt++; ans += P[s];
    }
    cout << cnt << " " << ans << "\n";
}