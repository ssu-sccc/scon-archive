#include <bits/stdc++.h>
using namespace std;

int N, K, X, A[22], O[22];
vector<int> G[22];
map<vector<int>, vector<int>> D[22];

void Print(vector<int> res){
    for(int i=0; i<K; i++){
        cout << count(res.begin(), res.end(), i) << " ";
        for(int j=0; j<N; j++) if(res[j] == i) cout << j + 1 << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K >> X;
    for(int i=0; i<N; i++){
        int c; cin >> c; G[i].resize(c);
        for(auto &j : G[i]) cin >> j, j--;
    }
    for(int i=0; i<N; i++) cin >> A[i], O[i] = i;
    sort(O, O+N, [](int u, int v){ return A[u] > A[v]; });

    for(auto i : G[O[0]]){
        vector<int> a(K), b(N, -1);
        a[i] = 1; b[O[0]] = i; D[0][a] = b;
    }
    for(int i=1; i<N; i++){
        for(const auto &[group,assign] : D[i-1]){
            for(auto j : G[O[i]]){
                if(group[j] == X) continue;
                auto a = group, b = assign;
                a[j] += 1; b[O[i]] = j;
                if(!D[i].count(a)) D[i][a] = b;
            }
        }
        if(D[i].empty()) D[i] = D[i-1];
    }
    Print(D[N-1].begin()->second);
}