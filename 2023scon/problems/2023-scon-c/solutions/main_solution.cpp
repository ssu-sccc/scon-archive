#include<bits/stdc++.h>
using namespace std;

int n, a[100100];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=3;i<=n;i++) if(a[i]-a[i-1] != a[2]-a[1]) return cout << "NO\n", 0;


    cout << "YES\n";
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    cout << "\n";
    for(int i=1;i<=n;i++) cout << "0 ";
    cout << "\n";
}