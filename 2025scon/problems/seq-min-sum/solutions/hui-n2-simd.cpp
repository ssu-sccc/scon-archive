#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;

int N;
alignas(32) int A[500'000], T[8];

int MinQuery(int l, int r){
    int res = 1e9;
    while(l < r && l % 8 != 0) res = min(res, A[l++]);
    while(l < r && r % 8 != 0) res = min(res, A[--r]);
    __m256i v = _mm256_set1_epi32(res);
    if(l < r){
        for(int i=l; i<r; i+=8){
            v = _mm256_min_epi32(v, _mm256_load_si256((const __m256i*)(A+i)));
        }
    }
    _mm256_store_si256((__m256i*)T, v);
    return *min_element(T, T+8);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) A[i] = MinQuery(i, N);
    cout << accumulate(A, A+N, 0LL);
}