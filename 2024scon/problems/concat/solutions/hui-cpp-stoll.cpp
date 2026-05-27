#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; string X, Y; cin >> N;
    for(int i=1; i<=N; i++){
        string s; cin >> s; X += s;
    }
    for(int i=1; i<=N; i++){
        string s; cin >> s; Y += s;
    }
    cout << min(stoll(X), stoll(Y));
}