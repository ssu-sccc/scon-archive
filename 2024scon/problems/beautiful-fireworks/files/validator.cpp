#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

vector<int> UF;

int find(int a) {
    return UF[a] = a == UF[a] ? a : find(UF[a]);
}
int merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return 0;
    UF[a] = b;
    return 1;
}

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(2, 200'000, "N");
    UF.resize(N + 1);
    iota(UF.begin(), UF.end(), 0);
    inf.readEoln();

    for (int i = 1; i < N; i++) {
        int a = inf.readInt(1, N, format("U_%d", i));
        inf.readSpace();
        int b = inf.readInt(1, N, format("V_%d", i));
        inf.readEoln();
        ensuref(merge(a, b), "cycle detected in %d", i);
    }

    inf.readInts(N, 1, 1'000'000, "W");

    inf.readEoln();
    inf.readEof();
}
