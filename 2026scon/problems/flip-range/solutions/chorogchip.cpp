#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; string s; cin >> n >> s;
    int cnt = 0;
    for (int i = 1; i < (int)s.size(); ++i) cnt += s[i-1] == s[i];
    cout << (cnt+1)/2;
}