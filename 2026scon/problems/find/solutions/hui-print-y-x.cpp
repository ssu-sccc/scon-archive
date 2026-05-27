#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

int Ask(int l, int r){
    if(l > r) return 0;
    if(r < 1) return 0;
    if(l > N) return 0;
    l = max(1, l); r = min(N, r);
    cout << "? " << r-l+1 << " ";
    for(int i=l; i<=r; i++) cout << i << " ";
    cout << endl;
    int res; cin >> res;
    return res;
}

int Find(int l, int r){
    int st = l;
    while(l < r){
        int m = (l + r) / 2;
        if(Ask(st, m)) r = m;
        else l = m + 1;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    int x = Find(1, N), y = Find(x+1, N);
    cout << "! " << y << " " << x << endl;
}