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

    int sent = -1; 

    for (int i = 1; i <= n - i + 1; i++) {
        if (i < n - i + 1) {
            A[i] = ask(i);
            A[n - i + 1] = ask(n - i + 1);
            if (sent == -1) sent = i;
        } else {
            A[i] = ask(i);
            if (sent == -1) sent = i;
        }

        if (q % 10 == 0 && sent != -1) {
            int now = ask(sent);
            if (A[sent] != now) flip();
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