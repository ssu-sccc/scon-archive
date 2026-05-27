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

    cout << N << "\n";
    for(int i=1;i<=N;i++) {
        cout << S+D*(i-1) << " \n"[i == N];
    }

    return 0;
}
