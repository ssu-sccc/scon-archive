#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<int> v(N);
    for(int &i : v) cin >> i;
    ll res = v.back();
    for(int i = N-1; i > 0; i--){
        v[i-1] = min(v[i],v[i-1]);
        res += v[i-1];
    }
    cout << res << "\n";
}    