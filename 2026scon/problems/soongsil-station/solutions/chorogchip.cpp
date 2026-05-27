#include <bits/stdc++.h>
using namespace std;

int res = 1'000'000;
int a, b, c, h;

void asd(int aa, int bb, int cc) {
    if (a-aa + b-bb + c-cc < h)
        res = min(res, aa+bb+cc);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> h;
    asd(a, b, c);
    asd(a, b, c/2);
    asd(a, b/2, c);
    asd(a, b/2, c/2);
    asd(a/2, b, c);
    asd(a/2, b, c/2);
    asd(a/2, b/2, c);
    asd(a/2, b/2, c/2);
    cout << res;
}