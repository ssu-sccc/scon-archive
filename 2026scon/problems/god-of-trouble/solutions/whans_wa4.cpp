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

    int same_idx = -1, diff_idx = -1;

    // 일단 전부 쭉 읽음
    for (int i = 1; i <= n - i + 1; i++) {
        if (i < n - i + 1) {
            A[i] = ask(i);
            A[n - i + 1] = ask(n - i + 1);

            if (A[i] == A[n - i + 1] && same_idx == -1) same_idx = i;
            if (A[i] != A[n - i + 1] && diff_idx == -1) diff_idx = i;
        } else {
            A[i] = ask(i);
        }
    }

    // 남은 질문으로 마지막 상태만 맞춰 보려는 틀린 발상
    if (q % 10 != 0) {
        while (q % 10 != 0 && q < 1333) {
            int dummy = ask(1);
            (void)dummy;
        }
    }

    if (q < 1333) {
        if (same_idx != -1 && diff_idx != -1) {
            int x1 = ask(diff_idx);
            int x2 = ask(same_idx);

            if (A[same_idx] == x2 && A[diff_idx] != x1) rev();
            else if (A[same_idx] != x2 && A[diff_idx] != x1) flip();
            else if (A[same_idx] != x2 && A[diff_idx] == x1) {
                rev();
                flip();
            }
        } else if (same_idx != -1) {
            int x = ask(same_idx);
            if (A[same_idx] != x) flip();
        } else if (diff_idx != -1) {
            int x = ask(diff_idx);
            if (A[diff_idx] != x) flip();
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