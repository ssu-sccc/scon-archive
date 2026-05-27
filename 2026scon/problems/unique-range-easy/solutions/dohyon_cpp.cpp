#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> ans(N + 1);
    ans[0] = 0;
    for (int i = 1; i < N; i += 2) {
        ans[i] = (i + 1) >> 1;
        ans[i + 1] = -ans[i];
    }
    for (int i = 0; i < N; i++)
        cout << ans[i] << ' ';
}