#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, c[111];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
            int x; cin >> x;
            c[x]++;
        }
    }

    int ans = 0;
    for(int i=1;i<=100;i++) for(int j=i+1;j<=100;j++) for(int k=j+1;k<=100;k++) {
        c[i]++, c[j]++, c[k]++;
        int key = 100;
        while(key && c[key] != 1) key--;
        if(key == i || key == j || key == k) ans++;
        c[i]--, c[j]--, c[k]--;
    }
    cout << ans;
}