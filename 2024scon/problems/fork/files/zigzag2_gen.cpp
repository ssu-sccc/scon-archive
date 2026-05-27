#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
 
    int N = opt<int>("N");
    int K = rnd.next(1, max(1, N/500));
 
    vector<int> A(N);
    for(int i=0;i<N;i++) A[i] = rnd.next((i%K)%2 ? -100'000 : -500'000, (i%K)%2 ? 500'000 : 100'000);
 
    cout << N << " " << K << "\n";
    for(int i=0;i<N;i++) cout << A[i] << " \n"[i == N-1];
 
    return 0;
}
