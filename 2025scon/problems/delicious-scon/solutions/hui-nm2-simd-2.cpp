#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;

int N, M, C, D, A[202];

alignas(32) int dp[2][25016], T[8];
vector<int> G[25252];
int Cost(int t, int k){ return M - abs(A[t] - k); }
int GetMax(int p, int l, int r){
    int res = 0;
    while(l <= r && l % 8 != 0) res = max(res, dp[p][l++]);
    while(l <= r && r % 8 != 7) res = max(res, dp[p][r--]);
    if(l > r) return res;

    __m256i vec = _mm256_setzero_si256(), reg[8];
    for(; l+63<=r; l+=64){
        for(int i=0; i<8; i++) reg[i] = _mm256_load_si256((const __m256i*)(dp[p]+l+i*8));
        for(int i=0; i<8; i++) vec = _mm256_max_epi32(vec, reg[i]);
    }
    for(; l<=r; l+=8){
        __m256i now = _mm256_load_si256((const __m256i*)(dp[p]+l));
        vec = _mm256_max_epi32(vec, now);
    }
    _mm256_store_si256((__m256i*)T, vec);
    return max(res, *max_element(T, T+8));
}
int Solve(int p){
    const auto &v = G[p];
    if(v.empty()) return 0;
    
    for(int i=0; i<v.size(); i++) dp[1][i] = Cost(1, v[i]);
    for(int i=2; i<=N; i++){
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