#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int mod = 1e9 + 7;
const int N = 200'202;
vector<int>G[N];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector S(n + 1, -1);
    auto Find = [&](auto &&self,int a)->int{return S[a] < 0 ? a : S[a] = self(self, S[a]);};
    auto Union = [&](int a,int b){
        a = Find(Find, a); b = Find(Find, b);
        if(a == b)return 0;
        if(S[a] > S[b])swap(a, b);
        S[a] += S[b]; S[b] = a;
        return 1;
    };
    int i = -1, j = -1;
    for(int s = 0; s < n; s++){
        int u, v; cin >> u >> v;
        if(Union(u, v)){
            G[u].push_back(v);
            G[v].push_back(u);
        }else{
            i = u;
            j = v;
        }
    }
    vector D(n + 1, 0);
    auto dfs = [&](auto &&self,int v,int b)->void{
        for(int nx : G[v])if(nx != b){
            D[nx] = D[v] ^ 1;
            self(self, nx, v);
        }
    };
    dfs(dfs, 1, -1);
    cout << (D[i] != D[j] ? 2 : 3) << "\n";
}
