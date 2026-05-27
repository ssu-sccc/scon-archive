
#include <bits/stdc++.h>

using namespace std;

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    int s, c, o, n; cin >> s >> c >> o >> n;
    s += n; c += 2*o;
    cout << min(s/3, c/6) << "\n";
}    