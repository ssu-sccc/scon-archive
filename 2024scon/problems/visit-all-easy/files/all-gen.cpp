#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
    
    int N = opt<int>("N");
    vector<array<int, 2>> v;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(i != j) v.push_back({i, j});
    shuffle(v.begin(), v.end());
    cout << v.size() << "\n";
    for(auto [x, y] : v) cout << N << " " << x << " " << y << "\n";
}