#include "testlib.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 4, "n");
    inf.readEoln();

    string s = inf.readString(::format("[ICP]{%d}", n), "s");
    // inf.readEoln();

    string target = "ICPC";
    int idx = 0;
    for (char c : s) {
        while (idx < 4 && target[idx] != c) {
            idx++;
        }

        ensuref(idx < 4, "S is not a valid subsequence of 'ICPC'");
        idx++;
    }

    int m = inf.readInt(1, 100, "m");
    inf.readEoln();

    string t = inf.readString(::format("[A-Z]{%d}", m), "t");
    // inf.readEoln();

    inf.readEof();
    return 0;
}