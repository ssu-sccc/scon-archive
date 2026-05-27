#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
    
    int T = 10'000;
    int N = opt<int>("N");
    
    cout << T << "\n";
    for(int i=1;i<=T;i++) {
        int S = rnd.next(1, N);
        int E = rnd.next(1, N);
        while(S == E) E = rnd.next(1, N);
    
        cout << N << " " << S << " " << E << "\n";
    }
    return 0;
}
