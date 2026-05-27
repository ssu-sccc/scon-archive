#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
 
    int N = atoi(argv[1]);

    cout << N << "\n";
    for(int i=1;i<=N;i++) {
        cout << rnd.next(-1'000'000'000, 1'000'000'000) << " \n"[i == N];
    }

    return 0;
}
