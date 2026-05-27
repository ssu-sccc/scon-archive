#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int n = opt<int>("n"), type = opt<int>("type");
    cout << n << " " << n - 1 << "\n";
    vector<tuple<int,int,long long>> E;
    for(int i=2; i<=n; i++) E.emplace_back(i-1, i, rnd.next(0, 7));
    if(type & 2) reverse(E.begin(), E.end());
    for(auto [u,v,w] : E){
        if(type & 1) cout << u << " " << v << " " << w << "\n";
        else cout << v << " " << u << " " << w << "\n";
    }
    return 0;
}