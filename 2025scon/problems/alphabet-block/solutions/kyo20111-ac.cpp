#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << min((2*c+b)/6, (a+d)/3);
}