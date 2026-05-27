#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
constexpr int MIN_N = 2;
constexpr int MAX_N = 1'000;

int main(int argc, char* argv[]) {
    registerInteraction(argc, argv);

    int n = inf.readInt(MIN_N, MAX_N, "n");
    int x = inf.readInt(1, n, "x");
    int y = inf.readInt(1, n, "y");

    if (x == y) {
        quitf(_fail, "Interactor input is invalid: x == y");
    }

    cout << n << endl;

    const int MAXQ = 25;
    int qcnt = 0;

    while (true) {
        string op = ouf.readToken("[!?]", "operation");

        if (op == "?") {
            ++qcnt;
            if (qcnt > MAXQ) {
                quitf(_wa, "Too many queries: %d > %d", qcnt, MAXQ);
            }

            int k = ouf.readInt(1, n, "k");
            vector<int> used(n + 1, 0);

            bool found = false;
            vector<int> I = ouf.readInts(k, 1, n, "I");
            for (int pos : I) {
        
                if (used[pos]) {
                    quitf(_wa, "Query #%d contains duplicate index %d", qcnt, pos);
                }
                used[pos] = 1;

                if (pos == x || pos == y) {
                    found = true;
                }
            }

            cout << (found ? 1 : 0) << endl;
        }
        else { // op == "!"
            int a = ouf.readInt(1, n, "answer_first");
            int b = ouf.readInt(1, n, "answer_second");

            if (a == b) {
                quitf(_wa, "Final answer positions must be distinct");
            }

            if (!ouf.seekEof()) {
                quitf(_pe, "Extra tokens after final answer");
            }

            if ((a == x && b == y) || (a == y && b == x)) {
                quitf(_ok, "Found both treasures in %d queries", qcnt);
            } else {
                quitf(_wa, "Wrong answer: expected {%d, %d}, found {%d, %d}", x, y, a, b);
            }
        }
    }
}