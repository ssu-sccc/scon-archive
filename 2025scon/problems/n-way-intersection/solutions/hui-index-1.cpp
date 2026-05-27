#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int X = 1;

int N, M, A[101010], On[101010];

ll CW(int flag){
    int st[] = {0, -1, 1};
    int ed[] = {M-1, M-2, M};

    int q = 0, r = 0;
    for(int i=st[flag]; i<=ed[flag]; i++) q += r > On[(i+N)%N], r = On[(i+N)%N];
    return 1LL * q * N + r;
}

ll CCW(int flag){
    int st[] = {N-1, N, N-2};
    int ed[] = {M, M+1, M-1};

    int q = 0, r = 0;
    for(int i=st[flag]; i>=ed[flag]; i--) q += r > On[(i+N)%N], r = On[(i+N)%N];
    return 1LL * q * N + r;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M; M--;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) On[A[i]-1] = i;
    cout << (CW(X/3) < CCW(X%3) ? "CW" : "CCW");
}