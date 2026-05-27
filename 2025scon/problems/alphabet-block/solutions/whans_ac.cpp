#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    a += d; b += 2 * c;
    cout << min(a / 3, b / 6) << "\n";
}