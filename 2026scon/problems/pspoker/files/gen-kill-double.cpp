#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int n = opt<int>("n"), range = opt<int>("range"), type = opt<int>("type");

    vector<pair<int,int>> seed;
    for(int i=0; i<range; i++){
        for(int j=0; j<range; j++){
            seed.emplace_back(1e9 - i, 1e9 - i - j);
        }
    }

    vector<pair<int,int>> v;
    for(int i=0; i<n; i++) v.push_back(seed[rnd.next(0, (int)seed.size()-1)]);
    
    if(type) for(auto &[a,b] : v) swap(a, b);

    cout << n << "\n";
    for(int i=0; i<n; i++) cout << v[i].first << " \n"[i+1==n];
    for(int i=0; i<n; i++) cout << v[i].second << " \n"[i+1==n];

    return 0;
}