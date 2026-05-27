#include <bits/stdc++.h>
using namespace std;

int N, Q, P[606060], R;
unordered_set<int> S[606060];
int Find(int v){ return v == P[v] ? v : P[v] = Find(P[v]); }
void Merge(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return;
    if(S[u].size() > S[v].size()) swap(u, v);
    for(auto i : S[u]) R += S[v].count(i^1);
    for(auto i : S[u]) S[v].insert(i);
    P[u] = v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> Q;
    iota(P, P+606060, 0);
    for(int i=2; i<=N*2+1; i++) S[i].insert(i);
    for(int q=1; q<=Q; q++){
        int u, v; cin >> u >> v;
        Merge(u*2, v*2+1);
        Merge(v*2, u*2+1);
        cout << R << "\n";
    }
}