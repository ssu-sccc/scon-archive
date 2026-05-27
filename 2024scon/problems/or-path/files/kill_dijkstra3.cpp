#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
 
    int N = 63;
    int M = 3*60;
 
    cout << N << " " << M << "\n";
    for(int i=1;i<=60;i++) {
        cout << "1 " << i+1 << " " << (1ll << i-1) << "\n";
        if(i < 60) cout << i+1 << " " << i+2 << " " << (1ll << i-1) << "\n";
        cout << i+1 << " " << N-1 << " " << (1ll << i-1) << "\n";
    }
    cout << N-1 << " " << N << " " << (1ll << 59) << "\n";
 
    return 0;
}
