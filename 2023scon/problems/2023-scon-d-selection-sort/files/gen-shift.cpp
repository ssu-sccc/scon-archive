#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int inc = opt<int>("inc");
    int sft = opt<int>("sft");
    int N = opt<int>("n");
    vector<int> V(N);
    iota(V.begin(), V.end(), 1);
    if(!inc) reverse(V.begin(), V.end());
    rotate(V.begin(), V.begin()+sft, V.end());
    cout << N << "\n";
    for(int i=0; i<V.size(); i++) cout << V[i] << " \n"[i+1==V.size()];
    return 0;
}