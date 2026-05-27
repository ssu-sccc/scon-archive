#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int SZ = 1 << 19;

int N, A[SZ+1], T[SZ<<1];
long long R[SZ+1];

void Update(int x, int v){
    T[x|=SZ] = v;
    for(T[x|=SZ]=v; x>>=1; ) T[x] = min(T[x<<1], T[x<<1|1]);
}

int Get(){
    int x = 1;
    while(x < SZ) x = x << 1 | (T[x<<1] > T[x<<1|1]);
    return x ^ SZ;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; memset(T, 0x3f, sizeof T);
    for(int i=1; i<=N; i++) cin >> A[i], T[i|SZ] = A[i];
    for(int i=SZ-1; i; i--) T[i] = min(T[i<<1], T[i<<1|1]);
    for(int i=1; i<=N; i++){
        int j = Get();
        R[T[i|SZ]] += abs(i - j);
        R[T[j|SZ]] += abs(i - j);
        if(i != j) Update(j, T[i|SZ]);
        Update(i, 1e9);
    }
    for(int i=1; i<=N; i++) cout << R[i] << " \n"[i==N];
}