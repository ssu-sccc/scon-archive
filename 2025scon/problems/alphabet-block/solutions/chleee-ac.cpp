#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    int s, c, o, n; cin >> s >> c >> o >> n;
    cout << min((s+n)/3, (c+2*o)/6) << endl;
    return 0;
}