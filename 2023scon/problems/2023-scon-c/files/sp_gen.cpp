#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc,char* argv[])
{
    int N = 100000;

    cout << N << "\n";
    for(int i=1;i<=N/2;i++) {
        cout << -1'000'000'000 << " " << 1'000'000'000 << " \n"[i == N/2];
    }

    return 0;
}
