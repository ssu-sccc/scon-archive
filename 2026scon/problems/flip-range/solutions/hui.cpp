#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, C=0; string S; cin >> N >> S;
    for(int i=1; i<N; i++) C += S[i-1] == S[i];
    cout << (C + 1) / 2;
}