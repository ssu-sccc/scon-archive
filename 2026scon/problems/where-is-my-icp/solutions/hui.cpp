#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    string S, T; cin >> N >> S >> M >> T;
    int C[128] = {0};
    for(auto c : S + T) C[c]++;
    if(C['I'] >= 1 && C['C'] >= 2 && C['P'] >= 1) cout << "m4us happy";
    else cout << "m4us sad";
}