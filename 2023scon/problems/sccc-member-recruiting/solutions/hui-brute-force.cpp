#include <bits/stdc++.h>
using namespace std;

int N, K, X, A[22], O[22], C[22], P[22];
vector<int> V[22];

void Print(){
    for(int i=1; i<=K; i++){
        cout << count(P+1, P+N+1, i) << " ";
        for(int j=1; j<=N; j++) if(P[j] == i) cout << j << " ";
        cout << "\n";
    }
}

bool Check(const vector<int> &vec, int idx, bool print=false){
    if(idx == vec.size()){
        if(print) Print();
        return true;
    }
    for(auto i : V[vec[idx]]){
        if(C[i] == X) continue;
        C[i] += 1; P[vec[idx]] = i;
        bool flag = Check(vec, idx+1, print);
        C[i] -= 1; P[vec[idx]] = 0;
        if(flag) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K >> X;
    for(int i=1; i<=N; i++){
        int s; cin >> s; V[i].resize(s);
        for(auto &j : V[i]) cin >> j;
    }
    for(int i=1; i<=N; i++) cin >> A[i];
    iota(O+1, O+N+1, 1);
    sort(O+1, O+N+1, [](int u, int v){ return A[u] > A[v]; });

    vector<int> R;
    for(int i=1; i<=N; i++){
        R.push_back(O[i]);
        memset(C, 0, sizeof C);
        if(!Check(R, 0)) R.pop_back();
    }
    Check(R, 0, true);
}