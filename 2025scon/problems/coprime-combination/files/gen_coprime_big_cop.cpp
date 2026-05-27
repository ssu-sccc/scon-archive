#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

    int isp[5050];
    for (int i = 1; i < 5050; i++)
        isp[i] = i;

    for (int i = 2; i * i < 5050; i++) {
        if (isp[i] == i) {
            for (int j = 2; i * j < 5050; j++) {
                isp[i * j] = i;
            }
        }
    }

    int cnt[5050][5050] = {};
    for (int i = 2; i < 5050; i++) {
        for (int j = 2; j < 5050; j++) {
            cnt[i][j] = cnt[i - 1][j];
        }
        int tmp = i;
        while (isp[tmp] != 1) {
            cnt[i][isp[tmp]]++;
            tmp /= isp[tmp];
        }
    }

    registerGen(argc, argv, 1);
    int mn = opt<int>(1), mx = opt<int>(2);

    if (mn > mx) {
        swap(mn, mx);
    }

    if (mn <= 200)
        mn += 200;
    if (mx <= 200)
        mx += 200;

    vector<bool> found(5050, false);
    printf("%d\n", mx - mn + 1);
    bool chk;
    for (int n1 = mn; n1 <= mx; n1++) {
        for (int r1 = 25; r1 >= 10; r1--) {
            for (int n2 = mx; n2 > mn; n2--) {
                for (int r2 = 25; r2 >= 10; r2--) {
                    chk = true;
                    for (int i = 2; i < 5000; i++) {
                        if (cnt[n1][i] - cnt[n1 - r1][i] - cnt[r1][i] > 0 &&
                            cnt[n2][i] - cnt[n2 - r2][i] - cnt[r2][i] > 0) {
                            chk = false;
                            break;
                        }
                    }
                    if (chk) {
                        printf("%d %d %d %d\n", n1, r1, n2, r2);
                        found[n1] = true;
                        break;
                    }
                }
                if (chk) break;
            }
            if (chk) break;
        }
    }

    for (int n1 = mn; n1 <= mx; n1++) {
        if (!found[n1]) {
            printf("%d %d %d %d\n", n1, n1 / 17, n1 - 107, (n1 - 103) / 42);
        }
    }
}
