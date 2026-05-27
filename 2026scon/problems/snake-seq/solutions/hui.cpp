#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 0xc0c0c0c0;

ll N, X[3030], Y[3030];
int D[3030][3030][2];
vector<pair<int,int>> V;

ll CCW(int p1, int p2, int p3){
    return (X[p2] - X[p1]) * (Y[p3] - Y[p1]) - (X[p3] - X[p1]) * (Y[p2] - Y[p1]);
}

void Solve(int p){
    vector<int> prv, nxt;
    for(int i=0; i<p; i++) if(X[i] < X[p] && Y[i] < Y[p]) prv.push_back(i);
    for(int i=p+1; i<=N; i++) if(X[p] < X[i] && Y[p] < Y[i]) nxt.push_back(i);
    sort(prv.begin(), prv.end(), [&p](int i, int j){ return CCW(p, i, j) > 0; });
    sort(nxt.begin(), nxt.end(), [&p](int i, int j){ return CCW(p, i, j) > 0; });
    for(int a=0, b=0, mx=INF; b<nxt.size(); b++){
        while(a < prv.size() && CCW(prv[a], p, nxt[b]) > 0) mx = max(mx, D[prv[a]][p][1]), a++;
        D[p][nxt[b]][0] = mx + 1;
    }
    reverse(prv.begin(), prv.end());
    reverse(nxt.begin(), nxt.end());
    for(int a=0, b=0, mx=INF; b<nxt.size(); b++){
        while(a < prv.size() && CCW(prv[a], p, nxt[b]) < 0) mx = max(mx, D[prv[a]][p][0]), a++;
        D[p][nxt[b]][1] = mx + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; V.resize(N);
    for(auto &[x,y] : V) cin >> x >> y;
    sort(V.begin(), V.end());
    for(int i=1; i<=N; i++) tie(X[i],Y[i]) = V[i-1];
    memset(D, 0xc0, sizeof D);
    for(int i=1; i<=N; i++) D[0][i][0] = D[0][i][1] = 1;
    for(int i=1; i<=N; i++) Solve(i);
    int R = 0;
    for(int i=0; i<=N; i++) for(int j=i+1; j<=N; j++) for(int k=0; k<2; k++) R = max(R, D[i][j][k]);
    cout << R;
}