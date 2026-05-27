#include <bits/stdc++.h>
using namespace std;

int ask(const vector<int>& v) {
    cout << "? " << v.size();
    for (int x : v) cout << " " << x;
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}

int askRange(int l, int r) {
    vector<int> v;
    for (int i = l; i <= r; i++) v.push_back(i);
    return ask(v);
}

int findLeftmost(int l, int r) {
    while (l < r) {
        int m = (l + r) >> 1;
        if (askRange(l, m)) r = m;
        else l = m + 1;
    }
    return l;
}

void solve() {
    int n;
    cin >> n;

    int first = findLeftmost(1, n);
    int second = -1;

    if (first <= n / 2) {
        if (n / 2 + 1 <= n && askRange(n / 2 + 1, n)) {
            second = findLeftmost(n / 2 + 1, n);
        } else {
            second = n; 
        }
    } else {
        if (1 <= n / 2 && askRange(1, n / 2)) {
            second = findLeftmost(1, n / 2);
        } else {
            second = 1; 
        }
    }

    if (first > second) swap(first, second);
    cout << "! " << first << " " << second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}