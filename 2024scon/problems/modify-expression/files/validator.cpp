#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 1999, "N");
    ensuref(n % 2, "n(%d) must be odd.", n);
    inf.readEoln();

    for (int i = 0; i < n; i++) {
        if (i) inf.readSpace();
        char c = inf.readChar();

        if (i % 2 == 0) {
            ensuref(c == 'T' || c == 'F', "A_%d(%c) must be T or F.", i, c);
        } else {
            ensuref(c == '&' || c == '|', "A_%d(%c) must be & or |.", i, c);
        }
    }
    inf.readEoln();

    char c = inf.readChar();
    ensuref(c == 'T' || c == 'F', "Target(%c) must be T or F.", c);
    inf.readEoln();
    inf.readEof();
}
