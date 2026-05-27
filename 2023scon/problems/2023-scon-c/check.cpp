#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MINB = -1e18;
const ll MAXB = 1e18;

const int _N = 100'000;
int N, A[_N+1];
ll B[_N+1], C[_N+1];


int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    N = inf.readInt();
    for (int i=1; i<=N; i++) A[i] = inf.readInt();

    string judge_res = ans.readString("[A-Z]{2,3}", "judge result");
    string res = ouf.readString("[A-Z]{2,3}", "july's result");
    if(res != judge_res) {
        quitf(_wa, "Judge answer is %s, but found %s", judge_res.c_str(), res.c_str());
    }

    if(res == "NO") {
        quitf(_ok, "OK");
    }

    for(int i=1;i<=N;i++) B[i] = ouf.readLong(MINB, MAXB, "B[" + to_string(i) + "]");
    for(int i=1;i<=N;i++) C[i] = ouf.readLong(MINB, MAXB, "C[" + to_string(i) + "]");

    for(int i=1;i<=N;i++) if(A[i] != B[i]+C[i]) {
        quitf(_wa, "A[%d] != B[%d] + C[%d]", i, i, i);
    }

    for(int i=2;i<=N;i++) if(B[i]-B[i-1] != B[2]-B[1]) {
        quitf(_wa, "B is not a arithmetic progression");
    }
    for(int i=2;i<=N;i++) if(C[i]-C[i-1] != C[2]-C[1]) {
        quitf(_wa, "C is not a arithmetic progression");
    }
    quitf(_ok, "OK");
}
