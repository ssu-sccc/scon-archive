#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    cout << "0 ";
    for(int i=0; i+1<N; i++){
        if(i % 2 == 0) cout << i / 2 + 1 << " ";
        else cout << -(i / 2 + 1) << " ";
    }
}