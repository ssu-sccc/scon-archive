#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll MAXX = 1e18;
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
 
    int N = atoi(argv[1]);
 
    ll X = rnd.next(0ll, (ll)1e18);

    cout << N << "\n";
    for(int i=1;i<=N;i++) {
        if(i < 60) {
            ll K = (rnd.next(0ll, (1ll << 60-i)-1) << i) + (((1ll << i)-1) & X);
            while(K > (ll)1e18) {
                K = (rnd.next(0ll, (1ll << 60-i)-1) << i) + (((1ll << i)-1) & X);
            }
            cout << K << " \n"[i == N];
        } else {
            cout << X << " \n"[i == N];
        }
    }
 
    return 0;
}
