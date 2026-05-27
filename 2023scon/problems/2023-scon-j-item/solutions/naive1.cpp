#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll a[200200];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+n);
    int ans = 0;
    do {
        int last = a[0], cnt = 1;
        for(int i=1;i<n;i++) {
            if((last & ((1 << cnt)-1)) == (a[i] & ((1 << cnt)-1))) {
                cnt++, last = a[i];
            }
        }
        ans = max(ans, cnt);
    } while(next_permutation(a, a+n));
    cout << ans;
}