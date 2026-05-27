#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define x first
#define y second
int CCW(const P &a,const P &b,const P &c){
    ll ret = a.x*b.y + b.x*c.y + c.x*a.y;
    ret   -= b.x*a.y + c.x*b.y + a.x*c.y;
    return (ret>0) - (ret<0);
}
ll len(const P &a,const P &b){
    ll dx = a.x-b.x, dy = a.y-b.y;
    return dx*dx + dy*dy;
}
// c 기준 반시계 정렬, 시계를 원하면 (a > b) (d < 0) 으로 바꾸면 됨
void rclock_sort(const P &c, vector<pair<P,int>>&v){
    sort(all(v), [&](auto a,auto b){
        if(a.x > c ^ b.x > c)return a.x < b.x;
        int d = CCW(c, a.x, b.x);
        if(d) return d > 0;
        return len(c, a.x) < len(c, b.x);
    });
}

void solve(){
    int n; cin >> n;
    vector<P> A(n);
    for (auto &[x_, y_] : A) cin >> x_ >> y_;
    A.push_back({0, 0});
    sort(all(A));
    vector<pair<P,int>> L, R;
    vector dp1(n+1, vector(n+1, 0)), dp2(n+1, vector(n+1, 0));
    vector<int> S(n+2);
    for (int s = 0; s <= n; s++) {
        L.clear(); R.clear();
        for (int e = 0; e <= n; e++) {
            if (A[s].x < A[e].x && A[s].y < A[e].y) R.push_back({A[e], e});
            if (A[s].x > A[e].x && A[s].y > A[e].y) L.push_back({A[e], e});
        }
        fill(all(S), 0);
        rclock_sort(A[s], L); rclock_sort(A[s], R);
        int s1 = R.size(), s2 = L.size();
        for (int e = s2-1; e >= 0; e--) {
            S[e] = max(S[e+1], dp1[L[e].y][s]);
        }
        int j = 0, k = 0, mx = 0;
        for (int e = 0; e < s1; e++) {
            auto [up, i] = R[e];
            while (j < s2 && CCW(A[s], up, L[j].x) > 0) {
                mx = max(mx, dp2[L[j].y][s]);
                j++;
            }
            while (k < s2 && CCW(A[s], up, L[k].x) >= 0) k++;
            dp1[s][i] = max(dp1[s][i], mx + 1);
            dp2[s][i] = max(dp2[s][i], S[k] + 1);
        } 
    }
    int ans = 0;
    for (int s = 0; s <= n; s++) {
        for (int e = 0; e <= n; e++) ans = max(ans, max(dp1[s][e], dp2[s][e]));
    }
    cout << ans << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}