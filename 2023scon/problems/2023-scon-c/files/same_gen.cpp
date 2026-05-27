#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
 
    int N = atoi(argv[1]);
    int X = atoi(argv[2]);

    cout << N << "\n";
    for(int i=1;i<=N;i++) {
        cout << X << " \n"[i == N];
    }

    return 0;
}
