#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N = 200000;

    ll X = rnd.next(0ll, (ll)1e18);

    cout << N << "\n";
    for(int i=0;i<N;i++) cout << X << " \n"[i == N-1];
}
