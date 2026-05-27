#include "testlib.h"
#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int mx = opt<int>("mx");
    vector<tuple<int,int,int>> V;
    for(int n=2; n<=mx; n++){
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(i != j) V.emplace_back(n, i, j);
    }
    shuffle(V.begin(), V.end());
    cout << V.size() << "\n";
    for(const auto &[n,s,e] : V) cout << n << " " << s << " " << e << "\n";
    return 0;
}