#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
 
    int N = 62;
    int M = 2*60;

    cout << N << " " << M << "\n";
    for(int i=1;i<=60;i++) {
        cout << "1 " << i+1 << " " << (1ll << i-1) << "\n";
        cout << i+1 << " " << N << " " << (1ll << i-1) << "\n";
    }
 
    return 0;
}
