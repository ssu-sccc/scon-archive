#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
 
    int N = 200000;

    ll K = 1ll << 59;
    ll X = rnd.next(0ll, (1ll << 59)-1);
    while((K | X) > (ll)1e18) {
        X = rnd.next(0ll, (1ll << 59)-1);
    }

    cout << N << "\n";
    for(int i=1;i<=N/2;i++) cout << X << " " << (X | K) << " \n"[i == N/2];
}
