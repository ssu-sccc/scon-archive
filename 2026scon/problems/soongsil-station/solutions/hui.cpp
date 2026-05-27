#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a[3], h; cin >> a[0] >> a[1] >> a[2] >> h;
    int res = a[0] + a[1] + a[2];
    for(int bit=0; bit<8; bit++){
        int now = 0, use = 0;
        for(int i=0; i<3; i++){
            if(bit >> i & 1) now += a[i] / 2, use += a[i] / 2;
            else now += a[i];
        }
        if(use < h) res = min(res, now);
    }
    cout << res;
}