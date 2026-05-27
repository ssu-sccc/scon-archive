#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, Q, D[101010], R[101010];
vector<int> G[101010];
vector<pair<int,int>> H[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> Q;
    for(int i=1,u,v; i<=M; i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    for(int i=1; i<=N; i++) D[i] = G[i].size();
    for(int i=1; i<=N; i++){
        sort(G[i].begin(), G[i].end(), [](int x, int y){ return D[x] < D[y]; });
        for(int j=0, k=0; j<G[i].size(); j=k){
            while(k < G[i].size() && D[G[i][j]] == D[G[i][k]]) k++;
            H[i].emplace_back(D[G[i][j]], k-j);
        }
    }
    for(int q=1; q<=Q; q++){
        int op; cin >> op;
        if(op == 1){
            ll x, v; cin >> x >> v;
            for(auto [deg,cnt] : H[x]) R[deg] += cnt * v;
        }
        else{
            int d; cin >> d;
            cout << R[d] << "\n";
        }
    }
}