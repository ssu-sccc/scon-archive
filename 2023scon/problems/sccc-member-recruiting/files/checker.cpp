#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int N, K, X;
vector<vector<int>> can_group;

set<int> parse(InStream &in) {
    set<int> res;
    for (int i = 1; i <= K; i++) {
        int cnt = in.readInt(0, X, "C_i");
        auto vec = in.readInts(cnt, 1, N, "D_{ij}");
        for (int j : vec) {
            // jth human wants ith group?
            if (find(can_group[j].begin(), can_group[j].end(), i) == can_group[j].end()) in.quitf(_wa, "%d human doesn't want %dth group.", j, i);

            if (res.count(j)) in.quitf(_wa, "%d human used in other group already.", j);
            res.insert(j);
        }
        if (!in.seekEoln()) in.quitf(_wa, "need eoln");
    }
    if (!in.seekEof()) in.quitf(_wa, "additional input");
    return res;
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    N = inf.readInt();
    K = inf.readInt();
    X = inf.readInt();

    can_group.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int c = inf.readInt();
        can_group[i] = inf.readInts(c);
    }

    auto A = parse(ans);
    auto B = parse(ouf);

    if (A != B) quitf(_wa, "wrong selection");
    else quitf(_ok, "same selection");
}
