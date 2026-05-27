#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 15, "N");
    inf.readSpace();
    int k = inf.readInt(1, 15, "K");
    inf.readSpace();
    int x = inf.readInt(1, 15, "X");
    inf.readEoln();

    ensuref(k * x <= 15, "K * X <= 15");

    for (int i = 0; i < n; i++) {
        int c = inf.readInt(1, k, "C_i");
        vector<int> vec(k + 1);
        for (int j = 0; j < c; j++) {
            inf.readSpace();
            int num = inf.readInt(1, k, "A_{ij}");
            ensuref(!vec[num], "not permutation");
            vec[num] = 1;
        }
        inf.readEoln();
    }

    set<int> mp;
    for (int i = 0; i < n; i++) {
        if (i) inf.readSpace();
        int score = inf.readInt(1, 1'000'000'000, "B_i");
        ensuref(!mp.count(score), "score should distinct.");
        mp.insert(score);
    }
    inf.readEoln();
    inf.readEof();
}
