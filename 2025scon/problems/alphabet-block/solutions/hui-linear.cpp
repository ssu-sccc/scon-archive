#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int s, c, o, n; cin >> s >> c >> o >> n;
    s += n; c += o * 2;
    // scon sccc
    // s * 3, c * 6
    int res = 0;
    while(s >= 3 && c >= 6) s -= 3, c -= 6, res++;
    cout << res;
}