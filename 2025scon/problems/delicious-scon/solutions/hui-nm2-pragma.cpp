#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;

int N, M, C, D, A[202];

alignas(32) int dp[2][25016];
vector<int> G[25252];
int Cost(int t, int k){ return M - abs(A[t] - k); }
void Clear(int x){
    memset(dp[x], 0, sizeof(dp[x][0]) * (M/C+10));
}
int GetMax(int p, int l, int r){
    int res = 0;
    for(int i=l; i<=r; i++) res = max(res, dp[p][i]);
    return res;
}
int Solve(int p){
    const auto &v = G[p];
    if(v.empty()) return 0;

    Clear(1);
    for(int i=0; i<v.size(); i++) dp[1][i] = Cost(1, v[i]);

    for(int i=2; i<=N; i++){
        Clear(i%2);
        for(int j=0; j<v.size(); j++){
            dp[i&1][j] = GetMax(i-1&1, max(0,j-D), min<int>(v.size()-1, j+D)) + Cost(i, v[j]);
        }
    }
    return *max_element(dp[N&1], dp[N&1]+v.size());
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> C >> D; D /= C;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=M; i++) G[i%C].push_back(i);

    int res = 0;
    for(int i=0; i<C; i++) res = max(res, Solve(i));
    cout << res;
}