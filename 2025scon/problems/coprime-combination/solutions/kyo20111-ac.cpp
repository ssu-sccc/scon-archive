#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int chk[5050], C[5050][5050], p1[5050], p2[5050];
 
void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
 
    memset(p1, 0, sizeof p1);
    memset(p2, 0, sizeof p2);
    for(int i=1;i<=a;i++) p1[i] += C[a][i];
    for(int i=1;i<=b;i++) p1[i] -= C[b][i];
    for(int i=1;i<=a-b;i++) p1[i] -= C[a-b][i];
 
    for(int i=1;i<=c;i++) p2[i] += C[c][i];
    for(int i=1;i<=d;i++) p2[i] -= C[d][i];
    for(int i=1;i<=c-d;i++) p2[i] -= C[c-d][i];
 
    for(int i=2;i<=min(a, c);i++) if(p1[i] && p2[i]) {
        cout << 0;
        return;
    }
    cout << 1;
}
 
int main() {
    for(int i=2;i<=5000;i++) if(!chk[i]) {
        for(int j=i;j<=5000;j+=i) chk[j] = i;
    }
    for(int i=2;i<=5000;i++) {
        memcpy(C[i], C[i-1], sizeof C[i-1]);
        for(int j=i;j>1;j=j/chk[j]) C[i][chk[j]]++;
    }
    cin.tie(0)->sync_with_stdio(0);
 
    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}
