#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int chk[5050], p1[5050], p2[5050];
 
void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
 
    memset(p1, 0, sizeof p1);
    memset(p2, 0, sizeof p2);
    for(int i=b+1;i<=a;i++) for(int j=i;j>1;j/=chk[j]) p1[chk[j]]++;
    for(int i=1;i<=a-b;i++) for(int j=i;j>1;j/=chk[j]) p1[chk[j]]--;
 
    for(int i=d+1;i<=c;i++) for(int j=i;j>1;j/=chk[j]) p2[chk[j]]++;
    for(int i=1;i<=c-d;i++) for(int j=i;j>1;j/=chk[j]) p2[chk[j]]--;
 
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
    cin.tie(0)->sync_with_stdio(0);
 
    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}
