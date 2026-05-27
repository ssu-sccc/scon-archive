#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n; cin >> n;
    auto ask = [&] (int i) {
        cout << "? " << i << endl;
        int x; cin >> x;
        return x;
    };
    vector<int> A(n+1);
    for (int s = 1; s <= n; s++) A[s] = ask(s);
    cout << "! ";
    for (int s = 1; s <= n; s++) cout << A[s] << " "; cout << endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}