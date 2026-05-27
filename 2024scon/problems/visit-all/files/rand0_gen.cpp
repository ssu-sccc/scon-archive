#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
    
    int T = 10'000;
    
    cout << T << "\n";
    for(int i=1;i<=T;i++) {
        int N = rnd.next(2, 1'000);
        int A = rnd.next(0, 1'000'000'000);
        int B = rnd.next(0, 1'000'000'000);
        int S = rnd.next(1, N);
        int E = rnd.next(1, N);
        while(S == E) E = rnd.next(1, N);
        
        if(rnd.next(0, 1)) A = 0;
        else B = 0;
    
        cout << N << " " << A << " " << B << " " << S << " " << E << "\n";
    }
    return 0;
}
