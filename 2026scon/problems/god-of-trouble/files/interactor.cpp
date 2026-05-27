#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
constexpr int MIN_N = 1;
constexpr int MAX_N = 1'000;
constexpr int MIN_A = 0;
constexpr int MAX_A = 1;


static const int MAX_Q = 1333;

void apply_flip(vector<int>& a) {
    for (int &i : a) i ^= 1;
}

void apply_reverse(vector<int>& a) {
    reverse(a.begin(), a.end());
}

void apply_operation(vector<int>& a, int op) {
    // 0: nothing
    // 1: flip
    // 2: reverse
    // 3: flip + reverse
    if (op == 1) {
        apply_flip(a);
    } else if (op == 2) {
        apply_reverse(a);
    } else if (op == 3) {
        apply_flip(a);
        apply_reverse(a);
    }
}

int main(int argc, char* argv[]) {
    registerInteraction(argc, argv);

    int N = inf.readInt(MIN_N, MAX_N, "N");
    inf.readEoln();
    
    auto A = inf.readInts(N, MIN_A, MAX_A, "A");
    inf.readEoln();
    
    auto Change = inf.readInts(133, 0, 3, "change");
    inf.readEoln();
    
    inf.readEof();
    
    
    
    cout << N << endl;

    int qcnt = 0, ccnt = 0;

    while (true) {
        string cmd = ouf.readToken();
        if (cmd != "?" && cmd != "!") {
            cout << -1 << endl;
            quitf(_wa, "invalid command");
        }

        if (cmd == "?") {
            int idx = ouf.readInt();
            if (idx < 1 || idx > N) {
                cout << -1 << endl;
                quitf(_wa, "invalid index range %d", idx);
            }

            qcnt++;
            if (qcnt > MAX_Q) {
                cout << -1 << endl;
                quitf(_wa, "Too many queries: %d", qcnt);
            }

            cout << A[idx-1] << endl;

            if (qcnt % 10 == 0) {
                int op = Change[ccnt++];
                apply_operation(A, op);
            }
        } else { // cmd == "!"
            auto ans = ouf.readInts(N, MIN_A, MAX_A, "outputA");

            for (int i = 0; i < N; i++) {
                if (ans[i] != A[i]) {
                    quitf(_wa, "Wrong answer at position %d: expected %d, found %d",
                          i+1, A[i], ans[i]);
                }
            }

            quitf(_ok, "Correct, used %d queries", qcnt);
        }
    }
}