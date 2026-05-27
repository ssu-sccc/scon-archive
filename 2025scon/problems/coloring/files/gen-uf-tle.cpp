#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>("n");

    int n1 = n/2;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    shuffle(a.begin(), a.end());
    cout << n << "\n";
    for(int i=1; i<=n1; i++) cout << a[i] << " " << a[i-1] << "\n";
    for(int i=n1;i<n;i++) cout << a[0] << ' ' << a[i] << '\n';
    return 0;
}