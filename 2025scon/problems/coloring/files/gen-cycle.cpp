#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int n = opt<int>("n");
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    shuffle(a.begin(), a.end());
    cout << n << "\n";
    for(int i=0; i<n; i++) cout << a[i] << " " << a[i+1<n?i+1:0] << "\n";
    return 0;
}