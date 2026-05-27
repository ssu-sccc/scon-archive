#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<tuple<int, int, string>> v(3);
    for(auto &[a, b, c] : v) cin >> a >> b >> c;
    sort(v.begin(), v.end(), [&](auto a, auto b) { return get<1>(a) < get<1>(b); });
    for(int i=0;i<3;i++) cout << get<1>(v[i])%100;
    cout << "\n";
    sort(v.begin(), v.end(), [&](auto a, auto b) { return get<0>(a) > get<0>(b); });
    for(int i=0;i<3;i++) cout << get<2>(v[i])[0];
}
