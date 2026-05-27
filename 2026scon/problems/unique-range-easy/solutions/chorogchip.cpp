#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int asd = n/2;
    if (!(n&1)) asd = -asd;
    do {
        cout << asd << ' ';
        if (asd > 0) asd = -asd;
        else if (asd < 0) asd = -asd-1;
        else break;
    } while (true);
}