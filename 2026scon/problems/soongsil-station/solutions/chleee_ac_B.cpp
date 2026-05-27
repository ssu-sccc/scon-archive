#include <bits/stdc++.h>

using namespace std;
int main() {

    int h;
    vector<int> v(3);
    for (auto &i : v) cin >> i; cin >> h;

    int ret = 424242;
    for (int i = 0; i < 8; i++) {
        int sum = 0, time = 0;
        for (int j = 0; j < 3; j++) {
            if (i & (1 << j)) sum += v[j]/2, time += v[j]/2;
            else time += v[j];
        }
        if (sum < h) ret = min(ret, time);
    }
    cout << ret << endl;
    return 0;
}