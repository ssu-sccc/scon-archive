#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q = 0;
    cin >> n;
    vector<int> A(n + 1, -1);

    auto ask = [&](int i) -> int {
        cout << "? " << i << endl;
        int x;
        if (!(cin >> x) || x == -1) exit(0);
        q++;
        return x;
    };

    auto answer = [&]() {
        cout << "! ";
        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << ' ';
            cout << A[i];
        }
        cout << endl;
    };

    auto flip = [&]() {
        for (int i = 1; i <= n; i++) if (A[i] != -1) A[i] ^= 1;
    };

    auto rev = [&]() {
        reverse(A.begin() + 1, A.end());
    };

    vector<int> S, D;

    auto read_pair = [&](int i) {
        A[i] = ask(i);
        A[n - i + 1] = ask(n - i + 1);
        if (A[i] == A[n - i + 1]) S.push_back(i);
        else D.push_back(i);
    };

    for (int i = 1; i <= n - i + 1; i++) {
        if (i < n - i + 1) read_pair(i);
        else A[i] = ask(i);

        if (q % 10 == 0) {
            if (S.empty() && !D.empty()) {
                int x = ask(D[0]);
                if (x != A[D[0]]) flip();
            } else if (D.empty() && !S.empty()) {
                int x = ask(S[0]);
                if (x != A[S[0]]) flip();
            } else if (!S.empty() && !D.empty()) {
                int x1 = ask(D[0]);
                int x2 = ask(S[0]);

                if (A[S[0]] == x2 && A[D[0]] != x1) rev();
                else if (A[S[0]] != x2 && A[D[0]] != x1) flip();
                else if (A[S[0]] != x2 && A[D[0]] == x1) {
                    rev();
                    flip();
                }
            }
        }
    }

    answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}