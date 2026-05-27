#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    const int MAX = 5'000;
    int T = inf.readInt(1, MAX, "T");
    inf.readEoln();
    for (int i = 1; i <= T; i++) {
        int n1 = inf.readInt(1, MAX, "n1");
        inf.readSpace();
        int r1 = inf.readInt(0, n1, "r1");
        inf.readSpace();
        int n2 = inf.readInt(1, MAX, "n2");
        inf.readSpace();
        int r2 = inf.readInt(0, n2, "r2");
        inf.readEoln();
    }
    inf.readEof();
}
