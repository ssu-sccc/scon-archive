#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>(1);
    int m = opt<int>(2);
    println(n, m);

    vector<int> cw(n / 2);
    iota(cw.begin(), cw.end(), 1);
    reverse(cw.begin(), cw.end());

    vector<int> ccw(n - n / 2);
    iota(ccw.begin(), ccw.end(), n / 2 + 1);

    vector<int> res(n);
    int i = 0, j = 0;
    int k = 0;
    while (i < cw.size() and j < ccw.size()) {
        int dir = rnd.next(0, 1);
        if (dir) res[k++] = cw[i++];
        else res[k++] = ccw[j++];
    }

    while (i < cw.size()) res[k++] = cw[i++];
    while (j < ccw.size()) res[k++] = ccw[j++];
    println(res);
}
