#include <bits/stdc++.h>
using namespace std;

int N, K, X, A[333], C[333], P[333];
vector<int> G[333];

bool DFS(int v){
    for(auto i : G[v]){
        if(C[i]) continue; C[i] = 1;
        if(!P[i] || DFS(P[i])){ P[i] = v; return true; }
    }
    return false;
}

pair<vector<int>, vector<vector<int>>> Run(vector<int> v){
    memset(P, 0, sizeof P);
    vector<int> S;
    vector<vector<int>> R(K);
    for(auto i : v){
        memset(C, 0, sizeof C);
        if(!DFS(i)) return {};
    }
    for(auto i : v) S.push_back(A[i]);
    sort(S.begin(), S.end(), greater<>());
    for(int i=0; i<K; i++) for(int j=0; j<X; j++) if(P[i*X+j]) R[i].push_back(P[i*X+j]);
    return {S, R};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K >> X;
    for(int i=1; i<=N; i++){
        int s; cin >> s;
        for(int j=1; j<=s; j++){
            int t; cin >> t;
            for(int k=1; k<=X; k++) G[i].push_back((t-1)*X+k-1);
        }
    }
    for(int i=1; i<=N; i++) cin >> A[i];

    vector<int> score;
    vector<vector<int>> match;
    for(int bit=1; bit<(1<<N); bit++){
        vector<int> idx;
        for(int i=0; i<N; i++) if(bit >> i & 1) idx.push_back(i+1);
        auto [a,b] = Run(idx);
        if(a.size() > score.size() || a.size() == score.size() && a > score) score = a, match = b;
    }

    for(auto v : match){
        cout << v.size() << " ";
        for(auto i : v) cout << i << " ";
        cout << "\n";
    }
}