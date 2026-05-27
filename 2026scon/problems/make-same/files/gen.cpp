#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int mode = opt<int>("mode", 0);
    int n;

    if (mode == 0) {
        n = opt<int>("n", MAX_N);
    } else if (mode == 1) {
        int l = opt<int>("l", MIN_N);
        int r = opt<int>("r", MAX_N);
        n = rnd.next(l, r);
    } else {
        quitf(_fail, "unknown mode");
    }

    int type = opt<int>("type", 0);

    vector<ll> a(n);

    if (type == 0) {
        for (int i = 0; i < n; i++) {
            a[i] = rnd.next(MIN_A, MAX_A);
        }
    }
    else if (type == 1) {
        ll x = rnd.next(MIN_A, MAX_A);
        for (int i = 0; i < n; i++) a[i] = x;
    }
    else if (type == 2) {
        for (int i = 0; i < n-1; i++) {
            a[i] = rnd.next(MIN_A, MAX_A);
        }

        if (n > 1) {
            ll sum = 0;
            for (ll x : a) sum += x; sum -= a[n-1];
            a[n-1] = 2 * n - sum % n;
        }
    }
    else if (type == 3) {
        ll x = rnd.next(MIN_A, MAX_A);
        for (int i = 0; i < n; i++) a[i] = x;

        if (n >= 2) {
            for (int t = 0; t < n; t++) {
                int i = rnd.next(1, n - 2);
                int j = rnd.next(i+1, n - 1);
                if (rnd.next(0, 1)) swap(i, j);
                --i; --j;
                ll k = rnd.next(1, MAX_A/1000);
                if (a[i] + k <= MAX_A && a[i+1] - k >= MIN_A && a[j] - k >= MIN_A && a[j+1] + k <= MAX_A) { 
                    a[i] += k;
                    a[i + 1] -= k;
                    a[j] -= k;
                    a[j + 1] += k;
                }
            }
        }
    } else if (type == 4) {
        for (int i = 0; i < n; i++) a[i] = MIN_A;
    } else if (type == 5) {
        for (int i = 0; i < n; i++) a[i] = MAX_A;
    }
    else {
        quitf(_fail, "unknown type");
    }
    ll S = 0, W = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        W += (i + 1) * a[i];
    }
    
    int q = opt<int>("q", rnd.next(MIN_Q, MAX_Q));
    auto A = a;
    vector<pair<ll,ll>> Q(q);
    int qtype = opt<int>("qtype", 0);
    if (qtype == 0) {
        for (auto &[i, x] : Q) {
            i = rnd.next(1, n);
            x = rnd.next(MIN_A, MAX_A);
        }
    } else if (qtype == 1){
        // make all same
        int to_x = rnd.next(MIN_A, MAX_A), j = 0;
        for (auto &[i, x] : Q) {
            j++;
            i = (j-1) % n + 1; x = to_x;
        }
    } else if (qtype == 2) {
        // yes to yes
        Q.clear();
        while (Q.size() < q) {
            int jop = 0;
            for (int t = 0; t < n; t++) {
                int i = rnd.next(1, n - 2);
                int j = rnd.next(i+1, n - 1);
                int op = 0;
                if (rnd.next(0, 1)) swap(i, j);
                --i; --j;
                ll k = rnd.next(1, 100);
                if (A[i] + k <= MAX_A && A[i+1] - k >= MIN_A && A[j] - k >= MIN_A && A[j+1] + k <= MAX_A) { 
                    A[i] += k;
                    A[i + 1] -= k;
                    A[j] -= k;
                    A[j + 1] += k;
                    op = 1;
                    vector<int> tmp = {i, i+1, j, j+1};
                    shuffle(tmp.begin(), tmp.end());
                    for (auto i : tmp) {
                        if (Q.size() < q) Q.push_back({(ll)i+1, A[i]});
                    }
                }
                if (op) {
                    jop = 1;
                    break;
                }
            }
            if (!jop) {
                for (int t = 0; t < 5; t++) {
                    int i = rnd.next(1, n);
                    if (Q.size() < q) Q.push_back({ll(i), A[i-1]});
                }
            }
        }
    } else if (qtype == 3) {
        // no to yes
        Q.clear();
        while (Q.size() < q) {
            ll x = rnd.next(MIN_A, MAX_A);
            for (ll &i : A) i = x;
            for (int t = 0; t < n; t++) {
                int i = rnd.next(1, n - 2);
                int j = rnd.next(i+1, n - 1);
                if (rnd.next(0, 1)) swap(i, j);
                --i; --j;
                ll k = rnd.next(1, MAX_A/1000);
                if (A[i] + k <= MAX_A && A[i+1] - k >= MIN_A && A[j] - k >= MIN_A && A[j+1] + k <= MAX_A) { 
                    A[i] += k;
                    A[i + 1] -= k;
                    A[j] -= k;
                    A[j + 1] += k;
                }
            }
            vector<int> I(n); iota(I.begin(), I.end(), 0);
            shuffle(I.begin(), I.end());
            for (int i = 0; i < n; i++) {
                int j = I[i];
                if (Q.size() < q) Q.push_back({(ll)j+1, A[j]});
            }
        }
        
    } else if (qtype == 4) {
        for (auto &[i, x] : Q) {
            i = rnd.next(1, n);
            x = a[i-1];
        }
    } 
    
    cout << n << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n-1];
    cout << q << '\n';
    for (auto [i, x] : Q) cout << i << ' ' << x << '\n';
    return 0;
}