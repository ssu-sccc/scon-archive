#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int chk[5050];
 
void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
 
    map<int, int> mp1, mp2;
    for(int i=b+1;i<=a;i++) for(int j=i;j>1;j/=chk[j]) mp1[chk[j]]++;
    for(int i=1;i<=a-b;i++) for(int j=i;j>1;j/=chk[j]) mp1[chk[j]]--;
 
    for(int i=d+1;i<=c;i++) for(int j=i;j>1;j/=chk[j]) mp2[chk[j]]++;
    for(int i=1;i<=c-d;i++) for(int j=i;j>1;j/=chk[j]) mp2[chk[j]]--;
 
    for(auto [x, y] : mp1) if(y && mp2.count(x) && mp2[x]) {
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
