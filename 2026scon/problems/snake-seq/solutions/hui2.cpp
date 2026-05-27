#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#define CROSS(i, j) (A[i][0] * A[j][1] - A[j][0] * A[i][1])
using namespace std;
using ll = long long;
constexpr int INF = 0xc0c0c0c0;

ll N;
alignas(32) ll A[3030][2];
alignas(32) int D[3030][3030][2];
pair<int,int> V[3030];
int prv[3030], nxt[3030], sz1, sz2;
inline bool Compare(int i, int j){ return CROSS(i, j) > 0; }

void Solve(int p){
    sz1 = sz2 = 0;
    ll x = A[p][0], y = A[p][1];
    for(int i=0; i<=N; i++) A[i][0] -= x, A[i][1] -= y;
    for(int i=0; i<p; i++) if(A[i][0] < 0 && A[i][1] < 0) prv[sz1++] = i;
    for(int i=p+1; i<=N; i++) if(A[i][0] > 0 && A[i][1] > 0) nxt[sz2++] = i;
    sort(prv, prv+sz1, Compare);
    sort(nxt, nxt+sz2, Compare);

    for(int a=0, b=0, mx=INF; b<sz2; b++){
        while(a < sz1 && CROSS(prv[a], nxt[b]) < 0) mx = max(mx, D[p][prv[a]][1]), a++;
        D[nxt[b]][p][0] = mx + 1;
    }

    for(int a=sz1-1, b=sz2-1, mx=INF; b>=0; b--){
        while(a >= 0 && CROSS(prv[a], nxt[b]) > 0) mx = max(mx, D[p][prv[a]][0]), a--;
        D[nxt[b]][p][1] = mx + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> V[i].first >> V[i].second;
    sort(V+1, V+N+1);
    for(int i=1; i<=N; i++) tie(A[i][0],A[i][1]) = V[i];
    memset(D, 0xc0, sizeof D);
    for(int i=1; i<=N; i++) D[i][0][0] = D[i][0][1] = 1;
    for(int i=1; i<=N; i++) Solve(i);
    int R = 0;
    for(int i=1; i<=N; i++) for(int j=0; j<i; j++) for(int k=0; k<2; k++) R = max(R, D[i][j][k]);
    cout << R;
}