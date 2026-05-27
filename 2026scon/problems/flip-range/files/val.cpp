#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(MINN, MAXN, "N");
    inf.readEoln();

    string t = inf.readToken(string("[01]{" + to_string(n) + "}").c_str(), "T");
    inf.readEoln();

    inf.readEof();
    return 0;
}