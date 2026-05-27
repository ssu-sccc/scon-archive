#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, 50000, "N");
    inf.readSpace();
    int M = inf.readInt(1, 20, "M");
    inf.readEoln();
    string regexPattern = "[01]{" + to_string(M) + "}";
    for (int i = 1; i <= N; i++) {
        inf.readToken(regexPattern, "S_" + to_string(i));
        inf.readEoln();
    }
    inf.readEof();
}
