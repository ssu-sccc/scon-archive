#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = __testlib_opts.count("n") ? opt<int>("n") : rnd.next(1, 15);
    int k = __testlib_opts.count("k") ? opt<int>("k") : rnd.next(1, 15);
    int x = __testlib_opts.count("x") ? opt<int>("x") : rnd.next(1, 15 / k);
    cout << n << " " << k << " " << x << "\n";

    for (int i = 0; i < n; i++) {
        int cnt = rnd.next(1, k);
        vector<int> vec(cnt);
        iota(vec.begin(), vec.end(), 1);
        shuffle(vec.begin(), vec.end());
        cout << cnt;
        for (int j = 0; j < cnt; j++) {
            cout << " " << vec[j];
        }
        cout << "\n";
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 1);
    shuffle(order.begin(), order.end());
    vector<int> num(n + 1);
    for (int i = 1; i <= n; i++) num[i] = rnd.next(num[i - 1] + 1, 1'000'000'000 - (n - i));
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << num[order[i]];
    }
    cout << "\n";
}
