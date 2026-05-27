#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1e9;
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
 
    int N = atoi(argv[1]);
    int S = rnd.next(-MAXA, MAXA);
    int D = rnd.next(0, 1) ? rnd.next(0, (MAXA-S)/N) : rnd.next((S-MAXA)/N, 0);
    int K = rnd.next(0, 1) ? -1 : 1;

    while(!(-MAXA <= min(S, S+D*(N-1))+K && max(S, S+D*(N-1))+K <= MAXA)) {
        S = rnd.next(-MAXA, MAXA);
        D = rnd.next(0, 1) ? rnd.next(0, (MAXA-S)/N) : rnd.next((S-MAXA)/N, 0);
    }

    int X = rnd.next(2, N);

    cout << N << "\n";
    for(int i=1;i<=N;i++) {
        cout << S+D*(i-1) + (i >= X ? K : 0) << " \n"[i == N];
    }

    return 0;
}
