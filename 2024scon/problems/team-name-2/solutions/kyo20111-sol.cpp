#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        string s; cin >> s;
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        for(auto c : s) {
            if('A' <= c && c <= 'Z') c1++;
            if('a' <= c && c <= 'z') c2++;
            if('0' <= c && c <= '9') c3++;
            if(c == '-') c4++;
        }
        if(c1 <= c2 && s.size() <= 10 && (c1 || c2 || c4)) return cout << s, 0;
    }
    assert(0);
}