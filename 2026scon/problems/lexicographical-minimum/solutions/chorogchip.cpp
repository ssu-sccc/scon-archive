#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; string s; cin >> n >> s;
    char last = s[s.size() - 1];
    bool repeat = false;
    string ans = ""; ans += last;
    for (int i = (int)s.size() - 2; i >= 0; --i) {
        char ch = s[i];
        if (ch == last) {
            if (repeat) ans += ch;
            continue;
        }
        repeat = ch < last;
        last = ch;
        ans += ch;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}