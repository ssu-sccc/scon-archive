#include <bits/stdc++.h>
using namespace std;

pair<int,int> operator + (const pair<int,int> &a, const pair<int,int> &b){
    return {a.first + b.first, a.second + b.second};
}

int N, S, E;
pair<int,int> D[9][1<<9];

void Solve(){
    cin >> N >> S >> E; S--; E--;
    if(N > 9){ cout << -1 << "\n"; return; }
    for(int i=0; i<N; i++) for(int j=0; j<(1<<N); j++) D[i][j] = {1e9, 0};
    priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<>> Q;
    Q.emplace(0, 0, S, 1<<S); D[S][1<<S] = {0, 0};
    while(!Q.empty()){
        auto [dst,cst,v,vis] = Q.top(); Q.pop();
        if(D[v][vis].first != dst || D[v][vis].second != cst) continue;
        auto c1 = make_pair(dst+1, cst), c2 = make_pair(dst+1, cst+1);
        for(auto x : {v-1, v+1}){
            if(x < 0 || x >= N) continue;
            for(auto nxt : {vis, vis | (1<<x)}){
                if(D[x][nxt] > c1) Q.emplace(dst+1, cst, x, nxt), D[x][nxt] = c1;
            }
        }
        for(auto x : {0, N-1}){
            for(auto nxt : {vis, vis | (1<<x)}){
                if(D[x][nxt] > c2) Q.emplace(dst+1, cst+1, x, nxt), D[x][nxt] = c2;
            }
        }
    }
    cout << D[E][(1<<N)-1].second << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int TC; cin >> TC;
    for(int tc=1; tc<=TC; tc++) Solve();
}