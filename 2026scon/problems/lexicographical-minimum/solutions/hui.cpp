#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; string S, T; cin >> N >> S;
    reverse(S.begin(), S.end());
    char L = 'Z';
    for(int i=0, j=0; i<N; i=j){
        while(j < S.size() && S[i] == S[j]) j++;
        T += string(S[i] < L ? j-i : 1, S[i]);
        L = S[i];
    }
    reverse(T.begin(), T.end());
    cout << T;
}