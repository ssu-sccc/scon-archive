#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
    
    int N = 300000, M = N-1;
    cout << N << " " << M << "\n";
    for(int i=1;i<N;i++) cout << i << " " << i+1 << " " << (1ll << 60)-1 << "\n";
    return 0;
}
