#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n, c = 0; cin >> n;
    vector<int> A(n+1, -1);
    auto ask = [&] (int i) {
        cout << i << flush;
        int x; cin >> x;
        if (x == -1) exit(0);
        c++;
        return x;
    };
    auto ans = [&] () {
        cout << "! ";
        for (int s = 1; s <= n; s++) {
            cout << A[s];
            if (s < n) cout << " ";
        } cout << endl;
    };
    auto flip = [&] () {
        for (int s = 1; s <= n; s++) A[s] ^= 1;
    };
    auto rev = [&] () { reverse(A.begin() + 1, A.end()); };
    vector<int> S, D;
    auto Q = [&] (int i) {
        A[i] = ask(i);
        A[n-i+1] = ask(n-i+1);
        if (A[i] ^ A[n-i+1]) D.push_back(i);
        else S.push_back(i);
    };
    for (int i = 1; i <= n-i+1; i++) {
        if (i < n-i+1) {
            Q(i);
        } else {
            A[i] = ask(i);
        }
        if (c % 10 == 0) {
            if (S.empty()) {
                int op = ask(D[0]);
                op = ask(D[0]);
                if (A[D[0]] != op) flip();
            } else if (D.empty()) {
                int op = ask(S[0]);
                op = ask(S[0]);
                if (A[S[0]] != op) flip();
            } else {
                int op1 = ask(D[0]);
                int op2 = ask(S[0]);
                if (A[S[0]] == op2 && A[D[0]] != op1) rev();
                else if (A[S[0]] != op2 && A[D[0]] != op1) flip();
                else if (A[S[0]] != op2 && A[D[0]] == op1) rev(), flip();
            }
        }
    }
    ans();
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}