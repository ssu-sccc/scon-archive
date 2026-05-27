#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

// [1, k] * n, monotone increase
vector<int> GenMonotone(int n, int k){
    vector<int> v(n);
    for(auto &i : v) i = rnd.next(1, k);
    sort(v.begin(), v.end());
    return v;
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int n = opt<int>("n"), mx = opt<int>("mx"), inc = opt<int>("inc");
    auto v = GenMonotone(n, mx);
    if(!inc) reverse(v.begin(), v.end());
    cout << n << "\n";
    for(int i=0; i<n; i++) cout << v[i] << " \n"[i+1==n];
    return 0;
}