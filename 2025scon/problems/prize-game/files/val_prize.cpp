#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, 100, "N");
    inf.readEoln();
    for (int i = 1; i <= N; i++) {
        int n1 = inf.readInt(1, 100, "n1");
        inf.readSpace();
        int n2 = inf.readInt(1, 100, "n2");
        inf.readSpace();
        int n3 = inf.readInt(1, 100, "n3");
        inf.ensuref(n1 != n2 && n2 != n3 && n3 != n1, "Duplicate number exists");
        inf.readEoln();
    }
    inf.readEof();
}
